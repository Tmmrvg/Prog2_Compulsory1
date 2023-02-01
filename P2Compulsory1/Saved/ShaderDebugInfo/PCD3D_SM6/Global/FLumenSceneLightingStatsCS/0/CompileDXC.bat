@ECHO OFF
SET DXC="D:\EpicGames\UE_5.1\Engine\Binaries\ThirdParty\ShaderConductor\Win64\dxc.exe"
IF NOT EXIST %DXC% (
	ECHO Couldn't find dxc.exe under "D:\EpicGames\UE_5.1\Engine\Binaries\ThirdParty\ShaderConductor\Win64"
	GOTO :END
)
%DXC% -HV 2021 /auto-binding-space 0 /Zpr /O3 -Wno-parentheses-equality /T cs_6_6 /E LumenSceneLightingStatsCS /Fc LumenSceneLightingDebug.d3dasm /Fo LumenSceneLightingDebug.dxil LumenSceneLightingDebug.usf
:END
PAUSE
