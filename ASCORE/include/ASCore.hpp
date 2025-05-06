#pragma once

#ifdef ASCORE_EXPORTS
#define ASCORE_API __declspec(dllexport)
#else
#define ASCORE_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

    // 샘플 테스트 함수
    ASCORE_API void HelloCore();

    // 웹캠 초기화 및 해제
    ASCORE_API bool InitCamera();
    ASCORE_API void ReleaseCamera();

    // 현재 프레임을 RGB 포맷으로 복사 (width * height * 3 크기의 버퍼 필요)
    ASCORE_API bool GetFrameRGB(unsigned char* buffer, int width, int height);

#ifdef __cplusplus
}
#endif
