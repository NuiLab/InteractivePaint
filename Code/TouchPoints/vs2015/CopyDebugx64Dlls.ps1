﻿$debugFolder = ".\x64\Debug\"

if (!(Test-Path -path $debugFolder)) {New-Item $debugFolder -Type Directory}

if (!(Test-Path ($debugFolder + "Leap.dll") )) { Copy-Item .\dependencies\LeapSDK\lib\x64\Leap.dll $debugFolder -Force -Verbose }
if (!(Test-Path ($debugFolder + "libusb-1.0.dll") )) { Copy-Item .\dependencies\libusb-1.0.20\x64\dll\libusb-1.0.dll $debugFolder -Force -Verbose }
if (!(Test-Path ($debugFolder + "Tobii.EyeX.Client.dll") )) { Copy-Item .\dependencies\TobiiEyeXSDK_1.7.480\lib\x64\Tobii.EyeX.Client.dll $debugFolder -Force -Verbose }