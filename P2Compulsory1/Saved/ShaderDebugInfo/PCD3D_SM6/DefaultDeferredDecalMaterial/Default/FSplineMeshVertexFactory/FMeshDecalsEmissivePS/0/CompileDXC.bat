@ECHO OFF
SET DXC="D:\EpicGames\UE_5.1\Engine\Binaries\ThirdParty\ShaderConductor\Win64\dxc.exe"
IF NOT EXIST %DXC% (
	ECHO Couldn't find dxc.exe under "D:\EpicGames\UE_5.1\Engine\Binaries\ThirdParty\ShaderConductor\Win64"
	GOTO :END
)
%DXC% /auto-binding-space 0 /Zpr /O3 -Wno-parentheses-equality /T ps_6_6 /E MainPS /Fc MeshDecals.d3dasm /Fo MeshDecals.dxil MeshDecals.usf
:END
PAUSE