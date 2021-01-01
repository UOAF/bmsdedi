#define WIN32_LEAN_AND_MEAN
#include "D3D11DeviceContextWrapper.h"
#include "d3d11.h"
#include "d3d11_wrapper.h"
#include "shared.h"

HRESULT D3D11DeviceContextWrapper::QueryInterface(REFIID riid, void** ppvObj)
{
    if ((riid == IID_IUnknown) && ppvObj)
    {
        AddRef();

        *ppvObj = this;

        return S_OK;
    }

    return d3d11_device_context_->QueryInterface(riid, ppvObj);
}

ULONG D3D11DeviceContextWrapper::AddRef()
{
    return d3d11_device_context_->AddRef();
}

ULONG D3D11DeviceContextWrapper::Release()
{
    auto count = d3d11_device_context_->Release();
    return count;
}

void D3D11DeviceContextWrapper::GetDevice(ID3D11Device** ppDevice)
{
    d3d11_device_context_->GetDevice(ppDevice);
}

HRESULT
D3D11DeviceContextWrapper::GetPrivateData(REFGUID guid, UINT* pDataSize,
                                          void* pData)
{
    return d3d11_device_context_->GetPrivateData(guid, pDataSize, pData);
}

HRESULT
D3D11DeviceContextWrapper::SetPrivateData(REFGUID guid, UINT DataSize,
                                          const void* pData)
{
    return d3d11_device_context_->SetPrivateData(guid, DataSize, pData);
}

HRESULT D3D11DeviceContextWrapper::SetPrivateDataInterface(
    REFGUID guid, const IUnknown* pData)
{
    return d3d11_device_context_->SetPrivateDataInterface(guid, pData);
}

void D3D11DeviceContextWrapper::VSSetConstantBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer* const* ppConstantBuffers)
{
    d3d11_device_context_->VSSetConstantBuffers(StartSlot, NumBuffers,
                                                ppConstantBuffers);
}

void D3D11DeviceContextWrapper::PSSetShaderResources(
    UINT StartSlot, UINT NumViews,
    ID3D11ShaderResourceView* const* ppShaderResourceViews)
{
    d3d11_device_context_->PSSetShaderResources(StartSlot, NumViews,
                                                ppShaderResourceViews);
}

void D3D11DeviceContextWrapper::PSSetShader(
    ID3D11PixelShader* pPixelShader,
    ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances)
{
    d3d11_device_context_->PSSetShader(pPixelShader, ppClassInstances,
                                       NumClassInstances);
}

void D3D11DeviceContextWrapper::PSSetSamplers(
    UINT StartSlot, UINT NumSamplers, ID3D11SamplerState* const* ppSamplers)
{
    d3d11_device_context_->PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void D3D11DeviceContextWrapper::VSSetShader(
    ID3D11VertexShader* pVertexShader,
    ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances)
{
    d3d11_device_context_->VSSetShader(pVertexShader, ppClassInstances,
                                       NumClassInstances);
}

void D3D11DeviceContextWrapper::DrawIndexed(UINT IndexCount,
                                            UINT StartIndexLocation,
                                            INT BaseVertexLocation)
{
    if (shouldRender())
    {
        d3d11_device_context_->DrawIndexed(IndexCount, StartIndexLocation,
                                           BaseVertexLocation);
    }
}

void D3D11DeviceContextWrapper::Draw(UINT VertexCount, UINT StartVertexLocation)
{
    if (shouldRender())
    {
        d3d11_device_context_->Draw(VertexCount, StartVertexLocation);
    }
}

HRESULT
D3D11DeviceContextWrapper::Map(ID3D11Resource* pResource, UINT Subresource,
                               D3D11_MAP MapType, UINT MapFlags,
                               D3D11_MAPPED_SUBRESOURCE* pMappedResource)
{
    return d3d11_device_context_->Map(pResource, Subresource, MapType, MapFlags,
                                      pMappedResource);
}

void D3D11DeviceContextWrapper::Unmap(ID3D11Resource* pResource,
                                      UINT Subresource)
{
    d3d11_device_context_->Unmap(pResource, Subresource);
}

void D3D11DeviceContextWrapper::PSSetConstantBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer* const* ppConstantBuffers)
{
    d3d11_device_context_->PSSetConstantBuffers(StartSlot, NumBuffers,
                                                ppConstantBuffers);
}

void D3D11DeviceContextWrapper::IASetInputLayout(
    ID3D11InputLayout* pInputLayout)
{
    d3d11_device_context_->IASetInputLayout(pInputLayout);
}

void D3D11DeviceContextWrapper::IASetVertexBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer* const* ppVertexBuffers,
    const UINT* pStrides, const UINT* pOffsets)
{
    d3d11_device_context_->IASetVertexBuffers(
        StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
}

void D3D11DeviceContextWrapper::IASetIndexBuffer(ID3D11Buffer* pIndexBuffer,
                                                 DXGI_FORMAT Format,
                                                 UINT Offset)
{
    d3d11_device_context_->IASetIndexBuffer(pIndexBuffer, Format, Offset);
}

void D3D11DeviceContextWrapper::DrawIndexedInstanced(UINT IndexCountPerInstance,
                                                     UINT InstanceCount,
                                                     UINT StartIndexLocation,
                                                     INT BaseVertexLocation,
                                                     UINT StartInstanceLocation)
{
    if (shouldRender())
    {
        d3d11_device_context_->DrawIndexedInstanced(
            IndexCountPerInstance, InstanceCount, StartIndexLocation,
            BaseVertexLocation, StartInstanceLocation);
    }
}

void D3D11DeviceContextWrapper::DrawInstanced(UINT VertexCountPerInstance,
                                              UINT InstanceCount,
                                              UINT StartVertexLocation,
                                              UINT StartInstanceLocation)
{
    d3d11_device_context_->DrawInstanced(VertexCountPerInstance, InstanceCount,
                                         StartVertexLocation,
                                         StartInstanceLocation);
}

void D3D11DeviceContextWrapper::GSSetConstantBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer* const* ppConstantBuffers)
{
    d3d11_device_context_->GSSetConstantBuffers(StartSlot, NumBuffers,
                                                ppConstantBuffers);
}

void D3D11DeviceContextWrapper::GSSetShader(
    ID3D11GeometryShader* pShader, ID3D11ClassInstance* const* ppClassInstances,
    UINT NumClassInstances)
{
    d3d11_device_context_->GSSetShader(pShader, ppClassInstances,
                                       NumClassInstances);
}

void D3D11DeviceContextWrapper::IASetPrimitiveTopology(
    D3D11_PRIMITIVE_TOPOLOGY Topology)
{
    d3d11_device_context_->IASetPrimitiveTopology(Topology);
}

void D3D11DeviceContextWrapper::VSSetShaderResources(
    UINT StartSlot, UINT NumViews,
    ID3D11ShaderResourceView* const* ppShaderResourceViews)
{
    d3d11_device_context_->VSSetShaderResources(StartSlot, NumViews,
                                                ppShaderResourceViews);
}

void D3D11DeviceContextWrapper::VSSetSamplers(
    UINT StartSlot, UINT NumSamplers, ID3D11SamplerState* const* ppSamplers)
{
    d3d11_device_context_->VSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void D3D11DeviceContextWrapper::Begin(ID3D11Asynchronous* pAsync)
{
    d3d11_device_context_->Begin(pAsync);
}

void D3D11DeviceContextWrapper::End(ID3D11Asynchronous* pAsync)
{
    d3d11_device_context_->End(pAsync);
}

HRESULT
D3D11DeviceContextWrapper::GetData(ID3D11Asynchronous* pAsync, void* pData,
                                   UINT DataSize, UINT GetDataFlags)
{
    return d3d11_device_context_->GetData(pAsync, pData, DataSize,
                                          GetDataFlags);
}

void D3D11DeviceContextWrapper::SetPredication(ID3D11Predicate* pPredicate,
                                               BOOL PredicateValue)
{
    d3d11_device_context_->SetPredication(pPredicate, PredicateValue);
}

void D3D11DeviceContextWrapper::GSSetShaderResources(
    UINT StartSlot, UINT NumViews,
    ID3D11ShaderResourceView* const* ppShaderResourceViews)
{
    d3d11_device_context_->GSSetShaderResources(StartSlot, NumViews,
                                                ppShaderResourceViews);
}

void D3D11DeviceContextWrapper::GSSetSamplers(
    UINT StartSlot, UINT NumSamplers, ID3D11SamplerState* const* ppSamplers)
{
    d3d11_device_context_->GSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void D3D11DeviceContextWrapper::OMSetRenderTargets(
    UINT NumViews, ID3D11RenderTargetView* const* ppRenderTargetViews,
    ID3D11DepthStencilView* pDepthStencilView)
{
    d3d11_device_context_->OMSetRenderTargets(NumViews, ppRenderTargetViews,
                                              pDepthStencilView);
}

void D3D11DeviceContextWrapper::OMSetRenderTargetsAndUnorderedAccessViews(
    UINT NumRTVs, ID3D11RenderTargetView* const* ppRenderTargetViews,
    ID3D11DepthStencilView* pDepthStencilView, UINT UAVStartSlot, UINT NumUAVs,
    ID3D11UnorderedAccessView* const* ppUnorderedAccessViews,
    const UINT* pUAVInitialCounts)
{
    d3d11_device_context_->OMSetRenderTargetsAndUnorderedAccessViews(
        NumRTVs, ppRenderTargetViews, pDepthStencilView, UAVStartSlot, NumUAVs,
        ppUnorderedAccessViews, pUAVInitialCounts);
}

void D3D11DeviceContextWrapper::OMSetBlendState(ID3D11BlendState* pBlendState,
                                                const FLOAT BlendFactor[4],
                                                UINT SampleMask)
{
    d3d11_device_context_->OMSetBlendState(pBlendState, BlendFactor,
                                           SampleMask);
}

void D3D11DeviceContextWrapper::OMSetDepthStencilState(
    ID3D11DepthStencilState* pDepthStencilState, UINT StencilRef)
{
    d3d11_device_context_->OMSetDepthStencilState(pDepthStencilState,
                                                  StencilRef);
}

void D3D11DeviceContextWrapper::SOSetTargets(UINT NumBuffers,
                                             ID3D11Buffer* const* ppSOTargets,
                                             const UINT* pOffsets)
{
    d3d11_device_context_->SOSetTargets(NumBuffers, ppSOTargets, pOffsets);
}

void D3D11DeviceContextWrapper::DrawAuto(void)
{
    d3d11_device_context_->DrawAuto();
}

void D3D11DeviceContextWrapper::DrawIndexedInstancedIndirect(
    ID3D11Buffer* pBufferForArgs, UINT AlignedByteOffsetForArgs)
{
    d3d11_device_context_->DrawIndexedInstancedIndirect(
        pBufferForArgs, AlignedByteOffsetForArgs);
}

void D3D11DeviceContextWrapper::DrawInstancedIndirect(
    ID3D11Buffer* pBufferForArgs, UINT AlignedByteOffsetForArgs)
{
    d3d11_device_context_->DrawInstancedIndirect(pBufferForArgs,
                                                 AlignedByteOffsetForArgs);
}

void D3D11DeviceContextWrapper::Dispatch(UINT ThreadGroupCountX,
                                         UINT ThreadGroupCountY,
                                         UINT ThreadGroupCountZ)
{
    d3d11_device_context_->Dispatch(ThreadGroupCountX, ThreadGroupCountY,
                                    ThreadGroupCountZ);
}

void D3D11DeviceContextWrapper::DispatchIndirect(ID3D11Buffer* pBufferForArgs,
                                                 UINT AlignedByteOffsetForArgs)
{
    d3d11_device_context_->DispatchIndirect(pBufferForArgs,
                                            AlignedByteOffsetForArgs);
}

void D3D11DeviceContextWrapper::RSSetState(
    ID3D11RasterizerState* pRasterizerState)
{
    d3d11_device_context_->RSSetState(pRasterizerState);
}

void D3D11DeviceContextWrapper::RSSetViewports(UINT NumViewports,
                                               const D3D11_VIEWPORT* pViewports)
{
    d3d11_device_context_->RSSetViewports(NumViewports, pViewports);
}

void D3D11DeviceContextWrapper::RSSetScissorRects(UINT NumRects,
                                                  const D3D11_RECT* pRects)
{
    d3d11_device_context_->RSSetScissorRects(NumRects, pRects);
}

void D3D11DeviceContextWrapper::CopySubresourceRegion(
    ID3D11Resource* pDstResource, UINT DstSubresource, UINT DstX, UINT DstY,
    UINT DstZ, ID3D11Resource* pSrcResource, UINT SrcSubresource,
    const D3D11_BOX* pSrcBox)
{
    if (shouldRender())
    {
        d3d11_device_context_->CopySubresourceRegion(
            pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource,
            SrcSubresource, pSrcBox);
    }
}

void D3D11DeviceContextWrapper::CopyResource(ID3D11Resource* pDstResource,
                                             ID3D11Resource* pSrcResource)
{
    d3d11_device_context_->CopyResource(pDstResource, pSrcResource);
}

void D3D11DeviceContextWrapper::UpdateSubresource(
    ID3D11Resource* pDstResource, UINT DstSubresource, const D3D11_BOX* pDstBox,
    const void* pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch)
{
    d3d11_device_context_->UpdateSubresource(pDstResource, DstSubresource,
                                             pDstBox, pSrcData, SrcRowPitch,
                                             SrcDepthPitch);
}

void D3D11DeviceContextWrapper::CopyStructureCount(
    ID3D11Buffer* pDstBuffer, UINT DstAlignedByteOffset,
    ID3D11UnorderedAccessView* pSrcView)
{
    d3d11_device_context_->CopyStructureCount(pDstBuffer, DstAlignedByteOffset,
                                              pSrcView);
}

void D3D11DeviceContextWrapper::ClearRenderTargetView(
    ID3D11RenderTargetView* pRenderTargetView, const FLOAT ColorRGBA[4])
{
    if (shouldRender())
    {
        d3d11_device_context_->ClearRenderTargetView(pRenderTargetView,
                                                     ColorRGBA);
    }
}

void D3D11DeviceContextWrapper::ClearUnorderedAccessViewUint(
    ID3D11UnorderedAccessView* pUnorderedAccessView, const UINT Values[4])
{
    if (shouldRender())
    {
        d3d11_device_context_->ClearUnorderedAccessViewUint(
            pUnorderedAccessView, Values);
    }
}

void D3D11DeviceContextWrapper::ClearUnorderedAccessViewFloat(
    ID3D11UnorderedAccessView* pUnorderedAccessView, const FLOAT Values[4])
{
    d3d11_device_context_->ClearUnorderedAccessViewFloat(pUnorderedAccessView,
                                                         Values);
}

void D3D11DeviceContextWrapper::ClearDepthStencilView(
    ID3D11DepthStencilView* pDepthStencilView, UINT ClearFlags, FLOAT Depth,
    UINT8 Stencil)
{
    if (shouldRender())
    {
        d3d11_device_context_->ClearDepthStencilView(
            pDepthStencilView, ClearFlags, Depth, Stencil);
    }
}

void D3D11DeviceContextWrapper::GenerateMips(
    ID3D11ShaderResourceView* pShaderResourceView)
{
    d3d11_device_context_->GenerateMips(pShaderResourceView);
}

void D3D11DeviceContextWrapper::SetResourceMinLOD(ID3D11Resource* pResource,
                                                  FLOAT MinLOD)
{
    d3d11_device_context_->SetResourceMinLOD(pResource, MinLOD);
}

FLOAT
D3D11DeviceContextWrapper::GetResourceMinLOD(ID3D11Resource* pResource)
{
    return d3d11_device_context_->GetResourceMinLOD(pResource);
}

void D3D11DeviceContextWrapper::ResolveSubresource(ID3D11Resource* pDstResource,
                                                   UINT DstSubresource,
                                                   ID3D11Resource* pSrcResource,
                                                   UINT SrcSubresource,
                                                   DXGI_FORMAT Format)
{
    d3d11_device_context_->ResolveSubresource(
        pDstResource, DstSubresource, pSrcResource, SrcSubresource, Format);
}

void D3D11DeviceContextWrapper::ExecuteCommandList(
    ID3D11CommandList* pCommandList, BOOL RestoreContextState)
{
    d3d11_device_context_->ExecuteCommandList(pCommandList,
                                              RestoreContextState);
}

void D3D11DeviceContextWrapper::HSSetShaderResources(
    UINT StartSlot, UINT NumViews,
    ID3D11ShaderResourceView* const* ppShaderResourceViews)
{
    d3d11_device_context_->HSSetShaderResources(StartSlot, NumViews,
                                                ppShaderResourceViews);
}

void D3D11DeviceContextWrapper::HSSetShader(
    ID3D11HullShader* pHullShader, ID3D11ClassInstance* const* ppClassInstances,
    UINT NumClassInstances)
{
    d3d11_device_context_->HSSetShader(pHullShader, ppClassInstances,
                                       NumClassInstances);
}

void D3D11DeviceContextWrapper::HSSetSamplers(
    UINT StartSlot, UINT NumSamplers, ID3D11SamplerState* const* ppSamplers)
{
    d3d11_device_context_->HSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void D3D11DeviceContextWrapper::HSSetConstantBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer* const* ppConstantBuffers)
{
    d3d11_device_context_->HSSetConstantBuffers(StartSlot, NumBuffers,
                                                ppConstantBuffers);
}

void D3D11DeviceContextWrapper::DSSetShaderResources(
    UINT StartSlot, UINT NumViews,
    ID3D11ShaderResourceView* const* ppShaderResourceViews)
{
    d3d11_device_context_->DSSetShaderResources(StartSlot, NumViews,
                                                ppShaderResourceViews);
}

void D3D11DeviceContextWrapper::DSSetShader(
    ID3D11DomainShader* pDomainShader,
    ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances)
{
    d3d11_device_context_->DSSetShader(pDomainShader, ppClassInstances,
                                       NumClassInstances);
}

void D3D11DeviceContextWrapper::DSSetSamplers(
    UINT StartSlot, UINT NumSamplers, ID3D11SamplerState* const* ppSamplers)
{
    d3d11_device_context_->DSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void D3D11DeviceContextWrapper::DSSetConstantBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer* const* ppConstantBuffers)
{
    d3d11_device_context_->DSSetConstantBuffers(StartSlot, NumBuffers,
                                                ppConstantBuffers);
}

void D3D11DeviceContextWrapper::CSSetShaderResources(
    UINT StartSlot, UINT NumViews,
    ID3D11ShaderResourceView* const* ppShaderResourceViews)
{
    d3d11_device_context_->CSSetShaderResources(StartSlot, NumViews,
                                                ppShaderResourceViews);
}

void D3D11DeviceContextWrapper::CSSetUnorderedAccessViews(
    UINT StartSlot, UINT NumUAVs,
    ID3D11UnorderedAccessView* const* ppUnorderedAccessViews,
    const UINT* pUAVInitialCounts)
{
    d3d11_device_context_->CSSetUnorderedAccessViews(
        StartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts);
}

void D3D11DeviceContextWrapper::CSSetShader(
    ID3D11ComputeShader* pComputeShader,
    ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances)
{
    d3d11_device_context_->CSSetShader(pComputeShader, ppClassInstances,
                                       NumClassInstances);
}

void D3D11DeviceContextWrapper::CSSetSamplers(
    UINT StartSlot, UINT NumSamplers, ID3D11SamplerState* const* ppSamplers)
{
    d3d11_device_context_->CSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void D3D11DeviceContextWrapper::CSSetConstantBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer* const* ppConstantBuffers)
{
    d3d11_device_context_->CSSetConstantBuffers(StartSlot, NumBuffers,
                                                ppConstantBuffers);
}

void D3D11DeviceContextWrapper::VSGetConstantBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer** ppConstantBuffers)
{
    d3d11_device_context_->VSGetConstantBuffers(StartSlot, NumBuffers,
                                                ppConstantBuffers);
}

void D3D11DeviceContextWrapper::PSGetShaderResources(
    UINT StartSlot, UINT NumViews,
    ID3D11ShaderResourceView** ppShaderResourceViews)
{
    d3d11_device_context_->PSGetShaderResources(StartSlot, NumViews,
                                                ppShaderResourceViews);
}

void D3D11DeviceContextWrapper::PSGetShader(
    ID3D11PixelShader** ppPixelShader, ID3D11ClassInstance** ppClassInstances,
    UINT* pNumClassInstances)
{
    d3d11_device_context_->PSGetShader(ppPixelShader, ppClassInstances,
                                       pNumClassInstances);
}

void D3D11DeviceContextWrapper::PSGetSamplers(UINT StartSlot, UINT NumSamplers,
                                              ID3D11SamplerState** ppSamplers)
{
    d3d11_device_context_->PSGetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void D3D11DeviceContextWrapper::VSGetShader(
    ID3D11VertexShader** ppVertexShader, ID3D11ClassInstance** ppClassInstances,
    UINT* pNumClassInstances)
{
    d3d11_device_context_->VSGetShader(ppVertexShader, ppClassInstances,
                                       pNumClassInstances);
}

void D3D11DeviceContextWrapper::PSGetConstantBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer** ppConstantBuffers)
{
    d3d11_device_context_->PSGetConstantBuffers(StartSlot, NumBuffers,
                                                ppConstantBuffers);
}

void D3D11DeviceContextWrapper::IAGetInputLayout(
    ID3D11InputLayout** ppInputLayout)
{
    d3d11_device_context_->IAGetInputLayout(ppInputLayout);
}

void D3D11DeviceContextWrapper::IAGetVertexBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer** ppVertexBuffers,
    UINT* pStrides, UINT* pOffsets)
{
    d3d11_device_context_->IAGetVertexBuffers(
        StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
}

void D3D11DeviceContextWrapper::IAGetIndexBuffer(ID3D11Buffer** pIndexBuffer,
                                                 DXGI_FORMAT* Format,
                                                 UINT* Offset)
{
    d3d11_device_context_->IAGetIndexBuffer(pIndexBuffer, Format, Offset);
}

void D3D11DeviceContextWrapper::GSGetConstantBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer** ppConstantBuffers)
{
    d3d11_device_context_->GSGetConstantBuffers(StartSlot, NumBuffers,
                                                ppConstantBuffers);
}

void D3D11DeviceContextWrapper::GSGetShader(
    ID3D11GeometryShader** ppGeometryShader,
    ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances)
{
    d3d11_device_context_->GSGetShader(ppGeometryShader, ppClassInstances,
                                       pNumClassInstances);
}

void D3D11DeviceContextWrapper::IAGetPrimitiveTopology(
    D3D11_PRIMITIVE_TOPOLOGY* pTopology)
{
    d3d11_device_context_->IAGetPrimitiveTopology(pTopology);
}

void D3D11DeviceContextWrapper::VSGetShaderResources(
    UINT StartSlot, UINT NumViews,
    ID3D11ShaderResourceView** ppShaderResourceViews)
{
    d3d11_device_context_->VSGetShaderResources(StartSlot, NumViews,
                                                ppShaderResourceViews);
}

void D3D11DeviceContextWrapper::VSGetSamplers(UINT StartSlot, UINT NumSamplers,
                                              ID3D11SamplerState** ppSamplers)
{
    d3d11_device_context_->VSGetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void D3D11DeviceContextWrapper::GetPredication(ID3D11Predicate** ppPredicate,
                                               BOOL* pPredicateValue)
{
    d3d11_device_context_->GetPredication(ppPredicate, pPredicateValue);
}

void D3D11DeviceContextWrapper::GSGetShaderResources(
    UINT StartSlot, UINT NumViews,
    ID3D11ShaderResourceView** ppShaderResourceViews)
{
    d3d11_device_context_->GSGetShaderResources(StartSlot, NumViews,
                                                ppShaderResourceViews);
}

void D3D11DeviceContextWrapper::GSGetSamplers(UINT StartSlot, UINT NumSamplers,
                                              ID3D11SamplerState** ppSamplers)
{
    d3d11_device_context_->GSGetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void D3D11DeviceContextWrapper::OMGetRenderTargets(
    UINT NumViews, ID3D11RenderTargetView** ppRenderTargetViews,
    ID3D11DepthStencilView** ppDepthStencilView)
{
    d3d11_device_context_->OMGetRenderTargets(NumViews, ppRenderTargetViews,
                                              ppDepthStencilView);
}

void D3D11DeviceContextWrapper::OMGetRenderTargetsAndUnorderedAccessViews(
    UINT NumRTVs, ID3D11RenderTargetView** ppRenderTargetViews,
    ID3D11DepthStencilView** ppDepthStencilView, UINT UAVStartSlot,
    UINT NumUAVs, ID3D11UnorderedAccessView** ppUnorderedAccessViews)
{
    d3d11_device_context_->OMGetRenderTargetsAndUnorderedAccessViews(
        NumRTVs, ppRenderTargetViews, ppDepthStencilView, UAVStartSlot, NumUAVs,
        ppUnorderedAccessViews);
}

void D3D11DeviceContextWrapper::OMGetBlendState(ID3D11BlendState** ppBlendState,
                                                FLOAT BlendFactor[4],
                                                UINT* pSampleMask)
{
    d3d11_device_context_->OMGetBlendState(ppBlendState, BlendFactor,
                                           pSampleMask);
}

void D3D11DeviceContextWrapper::OMGetDepthStencilState(
    ID3D11DepthStencilState** ppDepthStencilState, UINT* pStencilRef)
{
    d3d11_device_context_->OMGetDepthStencilState(ppDepthStencilState,
                                                  pStencilRef);
}

void D3D11DeviceContextWrapper::SOGetTargets(UINT NumBuffers,
                                             ID3D11Buffer** ppSOTargets)
{
    d3d11_device_context_->SOGetTargets(NumBuffers, ppSOTargets);
}

void D3D11DeviceContextWrapper::RSGetState(
    ID3D11RasterizerState** ppRasterizerState)
{
    d3d11_device_context_->RSGetState(ppRasterizerState);
}

void D3D11DeviceContextWrapper::RSGetViewports(UINT* pNumViewports,
                                               D3D11_VIEWPORT* pViewports)
{
    d3d11_device_context_->RSGetViewports(pNumViewports, pViewports);
}

void D3D11DeviceContextWrapper::RSGetScissorRects(UINT* pNumRects,
                                                  D3D11_RECT* pRects)
{
    d3d11_device_context_->RSGetScissorRects(pNumRects, pRects);
}

void D3D11DeviceContextWrapper::HSGetShaderResources(
    UINT StartSlot, UINT NumViews,
    ID3D11ShaderResourceView** ppShaderResourceViews)
{
    d3d11_device_context_->HSGetShaderResources(StartSlot, NumViews,
                                                ppShaderResourceViews);
}

void D3D11DeviceContextWrapper::HSGetShader(
    ID3D11HullShader** ppHullShader, ID3D11ClassInstance** ppClassInstances,
    UINT* pNumClassInstances)
{
    d3d11_device_context_->HSGetShader(ppHullShader, ppClassInstances,
                                       pNumClassInstances);
}

void D3D11DeviceContextWrapper::HSGetSamplers(UINT StartSlot, UINT NumSamplers,
                                              ID3D11SamplerState** ppSamplers)
{
    d3d11_device_context_->HSGetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void D3D11DeviceContextWrapper::HSGetConstantBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer** ppConstantBuffers)
{
    d3d11_device_context_->HSGetConstantBuffers(StartSlot, NumBuffers,
                                                ppConstantBuffers);
}

void D3D11DeviceContextWrapper::DSGetShaderResources(
    UINT StartSlot, UINT NumViews,
    ID3D11ShaderResourceView** ppShaderResourceViews)
{
    d3d11_device_context_->DSGetShaderResources(StartSlot, NumViews,
                                                ppShaderResourceViews);
}

void D3D11DeviceContextWrapper::DSGetShader(
    ID3D11DomainShader** ppDomainShader, ID3D11ClassInstance** ppClassInstances,
    UINT* pNumClassInstances)
{
    d3d11_device_context_->DSGetShader(ppDomainShader, ppClassInstances,
                                       pNumClassInstances);
}

void D3D11DeviceContextWrapper::DSGetSamplers(UINT StartSlot, UINT NumSamplers,
                                              ID3D11SamplerState** ppSamplers)
{
    d3d11_device_context_->DSGetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void D3D11DeviceContextWrapper::DSGetConstantBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer** ppConstantBuffers)
{
    d3d11_device_context_->DSGetConstantBuffers(StartSlot, NumBuffers,
                                                ppConstantBuffers);
}

void D3D11DeviceContextWrapper::CSGetShaderResources(
    UINT StartSlot, UINT NumViews,
    ID3D11ShaderResourceView** ppShaderResourceViews)
{
    d3d11_device_context_->CSGetShaderResources(StartSlot, NumViews,
                                                ppShaderResourceViews);
}

void D3D11DeviceContextWrapper::CSGetUnorderedAccessViews(
    UINT StartSlot, UINT NumUAVs,
    ID3D11UnorderedAccessView** ppUnorderedAccessViews)
{
    d3d11_device_context_->CSGetUnorderedAccessViews(StartSlot, NumUAVs,
                                                     ppUnorderedAccessViews);
}

void D3D11DeviceContextWrapper::CSGetShader(
    ID3D11ComputeShader** ppComputeShader,
    ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances)
{
    d3d11_device_context_->CSGetShader(ppComputeShader, ppClassInstances,
                                       pNumClassInstances);
}

void D3D11DeviceContextWrapper::CSGetSamplers(UINT StartSlot, UINT NumSamplers,
                                              ID3D11SamplerState** ppSamplers)
{
    d3d11_device_context_->CSGetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void D3D11DeviceContextWrapper::CSGetConstantBuffers(
    UINT StartSlot, UINT NumBuffers, ID3D11Buffer** ppConstantBuffers)
{
    d3d11_device_context_->CSGetConstantBuffers(StartSlot, NumBuffers,
                                                ppConstantBuffers);
}

void D3D11DeviceContextWrapper::ClearState(void)
{
    d3d11_device_context_->ClearState();
}

void D3D11DeviceContextWrapper::Flush(void)
{
    d3d11_device_context_->Flush();
}

D3D11_DEVICE_CONTEXT_TYPE D3D11DeviceContextWrapper::GetType(void)
{
    return d3d11_device_context_->GetType();
}

UINT D3D11DeviceContextWrapper::GetContextFlags(void)
{
    return d3d11_device_context_->GetContextFlags();
}

HRESULT
D3D11DeviceContextWrapper::FinishCommandList(BOOL RestoreDeferredContextState,
                                             ID3D11CommandList** ppCommandList)
{
    return d3d11_device_context_->FinishCommandList(RestoreDeferredContextState,
                                                    ppCommandList);
}
