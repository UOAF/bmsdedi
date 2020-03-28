/**
* Copyright (C) 2019 Elisha Riedlinger
*
* This software is  provided 'as-is', without any express  or implied  warranty. In no event will the
* authors be held liable for any damages arising from the use of this software.
* Permission  is granted  to anyone  to use  this software  for  any  purpose,  including  commercial
* applications, and to alter it and redistribute it freely, subject to the following restrictions:
*
*   1. The origin of this software must not be misrepresented; you must not claim that you  wrote the
*      original  software. If you use this  software  in a product, an  acknowledgment in the product
*      documentation would be appreciated but is not required.
*   2. Altered source versions must  be plainly  marked as such, and  must not be  misrepresented  as
*      being the original software.
*   3. This notice may not be removed or altered from any source distribution.
*/

#include "d3d9_wrapper.h"
#include "logging.h"

HRESULT m_IDirect3DSwapChain9::QueryInterface(THIS_ REFIID riid, void** ppvObj)
{
	if ((riid == IID_IDirect3DSwapChain9 || riid == IID_IUnknown) && ppvObj)
	{
		AddRef();

		*ppvObj = this;

		return S_OK;
	}

	HRESULT hr = ProxyInterface->QueryInterface(riid, ppvObj);

	if (SUCCEEDED(hr))
	{
		genericQueryInterface(riid, ppvObj, m_pDeviceEx);
	}

	return hr;
}

ULONG m_IDirect3DSwapChain9::AddRef(THIS)
{
	return ProxyInterface->AddRef();
}

ULONG m_IDirect3DSwapChain9::Release(THIS)
{
	return ProxyInterface->Release();
}

HRESULT m_IDirect3DSwapChain9::Present(THIS_ CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion, DWORD dwFlags)
{
	return ProxyInterface->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion, dwFlags);
}

HRESULT m_IDirect3DSwapChain9::GetFrontBufferData(THIS_ IDirect3DSurface9* pDestSurface)
{
	if (pDestSurface)
	{
		pDestSurface = static_cast<m_IDirect3DSurface9 *>(pDestSurface)->GetProxyInterface();
	}

	return GetFrontBufferData(pDestSurface);
}

HRESULT m_IDirect3DSwapChain9::GetBackBuffer(THIS_ UINT BackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface9** ppBackBuffer)
{
	HRESULT hr = ProxyInterface->GetBackBuffer(BackBuffer, Type, ppBackBuffer);

	if (SUCCEEDED(hr) && ppBackBuffer)
	{
		*ppBackBuffer = m_pDeviceEx->ProxyAddressLookupTable->FindAddress<m_IDirect3DSurface9>(*ppBackBuffer);
	}

	return hr;
}

HRESULT m_IDirect3DSwapChain9::GetRasterStatus(THIS_ D3DRASTER_STATUS* pRasterStatus)
{
	return ProxyInterface->GetRasterStatus(pRasterStatus);
}

HRESULT m_IDirect3DSwapChain9::GetDisplayMode(THIS_ D3DDISPLAYMODE* pMode)
{
	return ProxyInterface->GetDisplayMode(pMode);
}

HRESULT m_IDirect3DSwapChain9::GetDevice(THIS_ IDirect3DDevice9** ppDevice)
{
	if (!ppDevice)
	{
		return D3DERR_INVALIDCALL;
	}

	m_pDeviceEx->AddRef();

	*ppDevice = m_pDeviceEx;

	return D3D_OK;
}

HRESULT m_IDirect3DSwapChain9::GetPresentParameters(THIS_ D3DPRESENT_PARAMETERS* pPresentationParameters)
{
	return ProxyInterface->GetPresentParameters(pPresentationParameters);
}
