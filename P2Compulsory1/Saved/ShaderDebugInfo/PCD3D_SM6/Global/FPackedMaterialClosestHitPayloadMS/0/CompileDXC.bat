@ECHO OFF
SET DXC="D:\EpicGames\UE_5.1\Engine\Binaries\ThirdParty\ShaderConductor\Win64\dxc.exe"
IF NOT EXIST %DXC% (
	ECHO Couldn't find dxc.exe under "D:\EpicGames\UE_5.1\Engine\Binaries\ThirdParty\ShaderConductor\Win64"
	GOTO :END
)
%DXC% -HV 2021 /auto-binding-space 0 /exports PackedMaterialClosestHitPayloadMS /Zpr /O3 /enable-16bit-types -Wno-parentheses-equality /T lib_6_6 /Fc RayTracingBuiltInShaders.d3dasm /Fo RayTracingBuiltInShaders.dxil RayTracingBuiltInShaders.usf
:END
PAUSE
