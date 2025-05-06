#pragma once

#ifdef ASCORE_EXPORTS
#define ASCORE_API __declspec(dllexport)
#else
#define ASCORE_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

    // ���� �׽�Ʈ �Լ�
    ASCORE_API void HelloCore();

    // ��ķ �ʱ�ȭ �� ����
    ASCORE_API bool InitCamera();
    ASCORE_API void ReleaseCamera();

    // ���� �������� RGB �������� ���� (width * height * 3 ũ���� ���� �ʿ�)
    ASCORE_API bool GetFrameRGB(unsigned char* buffer, int width, int height);

#ifdef __cplusplus
}
#endif
