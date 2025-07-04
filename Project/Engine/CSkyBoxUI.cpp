#include "pch.h"
#include "CSkyBoxUI.h"
#include "CSkyBox.h"

CSkyBoxUI::CSkyBoxUI()
    : CRenderComponentUI(COMPONENT_TYPE::SKYBOX)
{
}

CSkyBoxUI::~CSkyBoxUI()
{
}

void CSkyBoxUI::Update_Com()
{
}

void CSkyBoxUI::Render_Com()
{
    Render_RCom();

    CSkyBox* pSkybox = dynamic_cast<CSkyBox*>(m_TargetObj->GetRenderComponent());
    if (pSkybox == nullptr)
        return;
    AssetPtr<CMaterial> pMaterial = pSkybox->GetMaterial();

    if (pMaterial.Get())
    {
        ImGui::NewLine();
        ImGui::Text("Skybox Texture");
        AssetPtr<CTexture> pTex = pMaterial->GetTexParam(TEX_PARAM::TEXCUBE_0);
        string name = "No Texture2D Exist";
        if (pTex.Get())
            name = to_str(pTex->GetName());
        ImGui::InputText("##SkyboxTex", const_cast<char*>(name.c_str()), name.size() + 1, ImGuiInputTextFlags_ReadOnly);
        if (ImGui::BeginDragDropTarget())
        {
            if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("ContentViewer"))
            {
                CAsset* Asset = *reinterpret_cast<CAsset**>(payload->Data);
                AssetPtr<CTexture> pTex = dynamic_cast<CTexture*>(Asset);
                if (pTex.Get())
                {
                    pSkybox->SetSkyboxTex(pTex);
                }
            }
            ImGui::EndDragDropTarget();
        }
    }
}
