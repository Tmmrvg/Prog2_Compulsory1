@ECHO OFF
SET DXC="D:\EpicGames\UE_5.1\Engine\Binaries\ThirdParty\ShaderConductor\Win64\dxc.exe"
IF NOT EXIST %DXC% (
	ECHO Couldn't find dxc.exe under "D:\EpicGames\UE_5.1\Engine\Binaries\ThirdParty\ShaderConductor\Win64"
	GOTO :END
)
%DXC% -HV 2021 /auto-binding-space 0 /Zpr /O1 -Wno-parentheses-equality /T cs_6_6 /E RadixSort_Downsweep /Fc RadixSortShaders.d3dasm /Fo RadixSortShaders.dxil RadixSortShaders.usf
:END
PAUSE
