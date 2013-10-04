@set PATH=%PATH%;"C:\Program Files (x86)\SEGGER\JLinkARM_V470a\"
start "JLink" "C:\Program Files (x86)\SEGGER\JLinkARM_V470a\JLinkGDBServer.exe" -if SWD -select USB -device STM32F407VG -if SWD -speed auto
