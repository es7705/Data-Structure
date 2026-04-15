# VSCode C/C++ IntelliSense 문제 해결 가이드
# VSCode C/C++ IntelliSense Troubleshooting Guide

---

## 증상 / Symptoms

- 구조체(struct), 클래스(class) 타입 이름이 **흰색**으로 표시됨 (초록색이어야 정상)
- `F12` (정의로 이동)가 작동하지 않음
- 자동완성이 안 되거나 멤버 변수/함수가 목록에 안 나옴
- 빨간 줄(오류 표시)이 잔뜩 생기는데 실제로 빌드는 됨

---

## 원인 / Root Cause

VSCode의 C/C++ 확장은 `.vcxproj`(Visual Studio 프로젝트 파일)를 **직접 읽지 못함**.  
따라서 `.vscode/c_cpp_properties.json`과 `.vscode/settings.json`에  
컴파일러 경로, 헤더 포함 경로 등을 **직접 명시**해줘야 IntelliSense가 정상 작동함.

> VSCode's C/C++ extension cannot read `.vcxproj` directly.  
> You must manually specify the compiler path and include paths  
> in `.vscode/c_cpp_properties.json` and `.vscode/settings.json`.

---

## 핵심 포인트 / Key Points

### 1. `includePath` 끝에 `/**` 를 붙여야 함
```json
// 잘못된 예 - 해당 폴더만 탐색, 하위 폴더 탐색 안 함
"C:/Program Files/.../MSVC/14.44.35207/include"

// 올바른 예 - 하위 폴더까지 재귀 탐색
"C:/Program Files/.../MSVC/14.44.35207/include/**"
```
> `/**` 없으면 MSVC 헤더 하위 폴더를 못 찾아서 타입 인식 실패 → 흰색으로 표시됨

---

### 2. `browse` 섹션이 반드시 있어야 함
```json
// F12(정의로 이동)와 시맨틱 색상(초록색 타입)을 담당하는 Tag Parser 설정
"browse": {
    "path": [
        "${workspaceFolder}",
        "C:/Program Files/.../MSVC/14.44.35207/include",
        "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/ucrt",
        "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/um"
    ],
    "limitSymbolsToIncludedHeaders": true  // 포함된 헤더만 심볼로 등록 (성능 최적화)
}
```
> IntelliSense 엔진은 두 가지로 구성됨:
> - **Tag Parser** → `browse` 기반 → F12, 타입 색상 담당
> - **IntelliSense** → `includePath` 기반 → 자동완성, 오류 표시 담당
>
> `browse` 섹션이 없으면 Tag Parser가 심볼 DB를 못 만들어서 타입 색상이 안 들어감

---

### 3. `settings.json`에 `enhancedColorization` 명시
```json
"C_Cpp.enhancedColorization": "enabled"  // 시맨틱 토큰 색상 명시적으로 활성화
```
> 기본값이 켜져 있긴 하지만 명시하면 확실하게 동작함

---

## 완성된 설정 파일 템플릿 / Complete Config Template

### `.vscode/c_cpp_properties.json`
```json
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**",
                "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/include/**",
                "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/ucrt/**",
                "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/um/**",
                "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/shared/**"
            ],
            "defines": [
                "_DEBUG",
                "WIN32",
                "_CONSOLE",
                "_WIN32",
                "_WIN64"
            ],
            "windowsSdkVersion": "10.0.26100.0",
            // cl.exe 경로: Visual Studio 설치 경로에 맞게 수정
            "compilerPath": "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-msvc-x64",
            "browse": {
                "path": [
                    "${workspaceFolder}",
                    "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/include",
                    "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/ucrt",
                    "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/um"
                ],
                "limitSymbolsToIncludedHeaders": true
            }
        }
    ],
    "version": 4
}
```

### `.vscode/settings.json` (IntelliSense 관련 핵심 항목만)
```json
{
    "C_Cpp.intelliSenseEngine": "default",           // IntelliSense 엔진 활성화
    "C_Cpp.errorSquiggles": "enabled",               // 오류 밑줄 표시 활성화
    "C_Cpp.autocomplete": "default",                 // 자동완성 활성화
    "C_Cpp.enhancedColorization": "enabled",         // 시맨틱 색상 활성화 (타입 초록색)
    "C_Cpp.intelliSenseEngineFallback": "enabled",   // 엔진 폴백 활성화
    "C_Cpp.default.compilerPath": "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/bin/Hostx64/x64/cl.exe",
    "C_Cpp.default.cStandard": "c17",
    "C_Cpp.default.cppStandard": "c++17",
    "C_Cpp.default.intelliSenseMode": "windows-msvc-x64",
    "C_Cpp.default.includePath": [
        "${workspaceFolder}/**",
        "C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.44.35207/include",
        "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/ucrt",
        "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/um",
        "C:/Program Files (x86)/Windows Kits/10/Include/10.0.26100.0/shared"
    ]
}
```

---

## MSVC 버전 확인 방법 / How to Check Your MSVC Version

경로에 있는 버전 번호(`14.44.35207`)가 다를 수 있음. 실제 설치된 버전 확인:

```
C:/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/
```
이 폴더를 탐색기로 열면 설치된 버전 폴더명이 보임. 그 이름으로 경로 교체.

---

## 설정 후 IntelliSense 초기화 방법 / Reset IntelliSense After Config Change

설정 파일을 수정한 뒤에도 반응이 없으면:

1. **VSCode 완전히 닫았다가 다시 열기** (가장 먼저 시도)
2. `Ctrl+Shift+P` → **C/C++: Reset IntelliSense Database** 실행
3. 파일을 열고 10~30초 대기 (IntelliSense DB 재구축 시간)
4. 그래도 안 되면 아래 캐시 폴더 삭제 후 재시작:
   ```
   %LOCALAPPDATA%\Microsoft\vscode-cpptools\ipch
   ```

---

## 진단 방법 / Diagnostics

문제가 지속되면 `Ctrl+Shift+P` → **C/C++: Log Diagnostics** 실행.  
출력창에서 확인할 항목:
- `Compiler Path` → 경로가 제대로 잡혔는지
- `Include Path` → 헤더 경로 목록이 맞는지
- `Defines` → 매크로 정의 확인
- `"No configuration provider"` 문구 → `c_cpp_properties.json` 문제
