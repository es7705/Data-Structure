# ch4_build.ps1
# 현재 파일 섹션(4-1, 4-2...)의 ExcludedFromBuild(Debug|x64)를 일시 제거 후 빌드, 복구
# → Visual Studio와 동일한 x64\Debug\ 경로에 결과물 생성

param(
    [string]$filePath,
    [switch]$runAfterBuild
)

$fileName = [System.IO.Path]::GetFileName($filePath)
if ($fileName -match '^(\d+-\d+)') {
    $section = $Matches[1]
} else {
    Write-Host "ERROR: 파일명에서 섹션 번호를 찾을 수 없습니다: $fileName" -ForegroundColor Red
    exit 1
}

$vcxprojPath = "d:\My data\Study\Coding\Data-Structure\ch4 Linked Data Structure and Linked List\ch4 Linked Data Structure and Linked List.vcxproj"
$msbuild     = 'C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\amd64\MSBuild.exe'
$exePath     = "d:\My data\Study\Coding\Data-Structure\ch4 Linked Data Structure and Linked List\x64\Debug\ch4 Linked Data Structure and Linked List.exe"

Write-Host "==> Section: $section" -ForegroundColor Cyan

# 원본 바이트 백업
$originalBytes = [System.IO.File]::ReadAllBytes($vcxprojPath)
$hasBOM = ($originalBytes[0] -eq 0xEF -and $originalBytes[1] -eq 0xBB -and $originalBytes[2] -eq 0xBF)
$enc = if ($hasBOM) { New-Object System.Text.UTF8Encoding($true) } else { [System.Text.Encoding]::UTF8 }
$text = $enc.GetString($originalBytes)

# 1단계: 모든 false를 true로 초기화 (Visual Studio가 바꿔놓은 것 복구)
$falseTag = '<ExcludedFromBuild Condition="''$(Configuration)|$(Platform)''==''Debug|x64''">false</ExcludedFromBuild>'
$trueTag  = '<ExcludedFromBuild Condition="''$(Configuration)|$(Platform)''==''Debug|x64''">true</ExcludedFromBuild>'
$modified = $text.Replace($falseTag, $trueTag)

# 2단계: 해당 섹션만 ExcludedFromBuild 태그 제거
$pattern = '(<ClCompile Include="' + [regex]::Escape($section) + '[^"]*">)([\s\S]*?)(</ClCompile>)'
$modified = [regex]::Replace($modified, $pattern, {
    param($m)
    $inner = $m.Groups[2].Value
    $inner = [regex]::Replace($inner, "`r`n      <ExcludedFromBuild Condition=""'[^']*'=='Debug\|x64'"">[^<]*</ExcludedFromBuild>", '')
    $inner = [regex]::Replace($inner, "`n      <ExcludedFromBuild Condition=""'[^']*'=='Debug\|x64'"">[^<]*</ExcludedFromBuild>", '')
    $m.Groups[1].Value + $inner + $m.Groups[3].Value
}, [System.Text.RegularExpressions.RegexOptions]::Singleline)

[System.IO.File]::WriteAllBytes($vcxprojPath, $enc.GetBytes($modified))

# 이전 빌드 obj 파일 삭제 (다른 섹션 obj 충돌 방지)
$objDir = "d:\My data\Study\Coding\Data-Structure\ch4 Linked Data Structure and Linked List\ch4 Link.6ef8b7d9\x64\Debug"
if (Test-Path $objDir) {
    Get-ChildItem -Path $objDir -Filter "*.obj" | Remove-Item -Force
}

Write-Host "==> Building [Debug|x64] section $section ..." -ForegroundColor Cyan
& $msbuild $vcxprojPath /p:Configuration=Debug /p:Platform=x64 /t:Build /v:minimal
$buildResult = $LASTEXITCODE

# 원본 복구
[System.IO.File]::WriteAllBytes($vcxprojPath, $originalBytes)
Write-Host "==> vcxproj restored." -ForegroundColor Gray

if ($buildResult -ne 0) {
    Write-Host "Build failed." -ForegroundColor Red
    exit 1
}

if ($runAfterBuild) {
    Write-Host "`n==> Running ...`n" -ForegroundColor Green
    cmd /c "chcp 949 >nul && `"$exePath`""
}
