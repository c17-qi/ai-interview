# PowerShell 脚本：自动下载并设置 MinGW-w64 作为 GCC 工具链

# 下载指定版本的 MinGW-w64 压缩包
$zipUrl = 'https://winlibs.com/downloads/Winlibs-gcc-12.2.0-16.7-mingw-w64-x86_64-posix-seh.zip'
$zipPath = "$env:TEMP\mingw.zip"
$installDir = 'C:\mingw64'

Write-Host "Downloading MinGW-w64..."
Invoke-WebRequest -Uri $zipUrl -OutFile $zipPath

Write-Host "Extracting to $installDir ..."
Add-Type -AssemblyName System.IO.Compression.FileSystem
[System.IO.Compression.ZipFile]::ExtractToDirectory($zipPath, $installDir)

# 目录结构可能包含子文件夹，将 bin 路径放到 PATH
$binPath = Get-ChildItem -Path $installDir -Directory | Select-Object -First 1 | ForEach-Object { Join-Path $_.FullName 'bin' }
Write-Host "找到 bin 目录： $binPath"

# 更新当前用户 PATH 变量
$currentPath = [Environment]::GetEnvironmentVariable('Path', 'User')
if ($currentPath -notlike "*${binPath}*") {
    [Environment]::SetEnvironmentVariable('Path', "$currentPath;$binPath", 'User')
    Write-Host "Added $binPath to PATH (user scope). Please restart VSCode for changes to take effect."
} else {
    Write-Host "$binPath is already in PATH."
}

Write-Host "Setup complete. Run 'gcc --version' in a new terminal to verify."
