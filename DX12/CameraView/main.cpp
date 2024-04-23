#include "CameraView.h"
#include "Triangle.h"
#include "TextureRender.h"
#include "TextureCube.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
	PSTR cmdLine, int showCmd)
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	::CoInitialize(nullptr);  //for WIC & COM
	try
	{
		TextureCube theApp(hInstance);
		if (!theApp.Initialize())
			return 0;
		/*CCameraDevice cameraDev;
		cameraDev.setD3DApp(&theApp);
		cameraDev.StartCamera();*/
		return theApp.Run();
	}
	catch (DxException& e)
	{
		MessageBox(nullptr, e.ToString().c_str(), L"HR Failed", MB_OK);
		return 0;
	}
}