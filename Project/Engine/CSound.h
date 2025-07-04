#pragma once
#include "CAsset.h"

class CSound :
    public CAsset
{
    friend class CAssetMgr;
public:
    CSound();
    ~CSound();
    CLONE_DISABLE(CSound);

private:
    FMOD::Sound* m_Sound;        // Sound 버퍼
    list<FMOD::Channel*>	m_listChannel;  // Sound 가 재생되고 있는 채널 리스트

public:
    // _iRoopCount : 0 (무한반복),  _fVolume : 0 ~ 1(Volume), _bOverlap : 소리 중첩 가능여부
    int Play(int _iRoopCount, float _fVolume, bool _bOverlap);
    void RemoveChannel(FMOD::Channel* _pTargetChannel);
    void Stop();

    // 0 ~ 1
    void SetVolume(float _f, int _iChannelIdx);

public:
    virtual int Load(const wstring& _FilePath) override;
    virtual int Save(const wstring& _FilePath, bool _Update = false) override { MessageBoxW(nullptr, L"사운드는 파일 저장을 지원하지 않습니다.", L"Sound Save Error", MB_OK); return S_OK; }


};
