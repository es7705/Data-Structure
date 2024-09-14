# josephus_build.ps1
param(
    [string]$filePath,
    [switch]$runAfterBuild
)

$vcxprojPath = "d:\My data\Study\Coding\Data-Structure\Josephus problem\Josephus problem\Josephus problem.vcxproj"
$msbuild     = 'C:\Program Files\Microsoft Visual Studio\2022\Community\MSBuild\Current\Bin\amd64\MSBuild.exe'
$exePath     = "d:\My data\Study\Coding\Data-Structure\Josephus problem\Josephus problem\x64\Debug\Josephus problem.exe"

Write-Host "==> Building Josephus problem [Debug|x64] ..." -ForegroundColor Cyan
& $msbuild $vcxprojPath /p:Configuration=Debug /p:Platform=x64 /t:Build /v:minimal
$buildResult = $LASTEXITCODE

if ($buildResult -ne 0) {
    Write-Host "Build failed." -ForegroundColor Red
    exit 1
}

if ($runAfterBuild) {
    Write-Host "`n==> Running ...`n" -ForegroundColor Green
    cmd /c "chcp 949 >nul && `"$exePath`""
}
