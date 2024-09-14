# ch5_build.ps1
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

$vcxprojPath = "d:\My data\Study\Coding\Data-Structure\ch5 stack\ch5 stack\ch5 stack.vcxproj"
$msbuild     = 'C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\amd64\MSBuild.exe'
$exePath     = "d:\My data\Study\Coding\Data-Structure\ch5 stack\ch5 stack\x64\Debug\ch5 stack.exe"

Write-Host "==> Section: $section" -ForegroundColor Cyan

$originalBytes = [System.IO.File]::ReadAllBytes($vcxprojPath)
$hasBOM = ($originalBytes[0] -eq 0xEF -and $originalBytes[1] -eq 0xBB -and $originalBytes[2] -eq 0xBF)
$enc = if ($hasBOM) { New-Object System.Text.UTF8Encoding($true) } else { [System.Text.Encoding]::UTF8 }
$text = $enc.GetString($originalBytes)

$falseTag = '<ExcludedFromBuild Condition="''$(Configuration)|$(Platform)''==''Debug|x64''">false</ExcludedFromBuild>'
$trueTag  = '<ExcludedFromBuild Condition="''$(Configuration)|$(Platform)''==''Debug|x64''">true</ExcludedFromBuild>'
$modified = $text.Replace($falseTag, $trueTag)

$pattern = '(<ClCompile Include="' + [regex]::Escape($section) + '[^"]*">)([\s\S]*?)(</ClCompile>)'
$modified = [regex]::Replace($modified, $pattern, {
    param($m)
    $inner = $m.Groups[2].Value
    $inner = [regex]::Replace($inner, "`r`n      <ExcludedFromBuild Condition=""'[^']*'=='Debug\|x64'"">[^<]*</ExcludedFromBuild>", '')
    $inner = [regex]::Replace($inner, "`n      <ExcludedFromBuild Condition=""'[^']*'=='Debug\|x64'"">[^<]*</ExcludedFromBuild>", '')
    $m.Groups[1].Value + $inner + $m.Groups[3].Value
}, [System.Text.RegularExpressions.RegexOptions]::Singleline)

[System.IO.File]::WriteAllBytes($vcxprojPath, $enc.GetBytes($modified))

$objDir = "d:\My data\Study\Coding\Data-Structure\ch5 stack\ch5 stack\ch5 stack.faa3e40f\x64\Debug"
if (Test-Path $objDir) {
    Get-ChildItem -Path $objDir -Filter "*.obj" | Remove-Item -Force
}

Write-Host "==> Building [Debug|x64] section $section ..." -ForegroundColor Cyan
& $msbuild $vcxprojPath /p:Configuration=Debug /p:Platform=x64 /t:Build /v:minimal
$buildResult = $LASTEXITCODE

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
