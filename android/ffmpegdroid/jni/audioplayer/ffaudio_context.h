#ifndef __FFAUDIO_CONTEXT_H
#define __FFAUDIO_CONTEXT_H

#include <libavformat/avformat.h>
#include <AL/al.h>

struct ALFFAudioDecoder;

/**
 * ��Ƶ������
 */
struct ALFFAudioContext {
	AVFormatContext *format_context; /* ��ʽ������ */
	double total_time; /* ����ʱ�� */
	int stream_index; /* ������ */
	AVStream *stream; /* �� */
	AVPacketList *packet_list; /* ���ݰ��б� */
	AVFrame *frame; /* ��Ƶ֡ */
	const uint8_t *frame_data; /* ָ����Ƶ֡���ݵ�ָ�룬���赥��������ͷ��ڴ� */
	size_t frame_data_size; /* ��Ƶ֡���ݵĴ�С */
};

/**
 * ��������
 * @param url �����ĵ�ַ
 * @param total_time �򿪵�������ʱ��
 * @return �ɹ�����0, ʧ�ܷ���-1
 */
int ffaudio_open_input_stream(const char* url, double *total_time);

/**
 * �ر���
 */
void ffaudio_close_input_stream();

/**
 * �򿪱�����
 * @param sample_rate ������
 * @param channel_type ͨ������
 * @param sample_type ��������
 * @return �ɹ�����0, ʧ�ܷ���-1
 */
void ffaudio_open_codec(ALuint *sample_rate, ALenum *channel_type, ALenum *sample_type);

/**
 * �رձ����
 */
void ffaudio_close_codec();

/**
 * ����
 * @param data, ����֮�������
 * @param length, ���Ľ��볤��
 * @param pts_in_seconds, ��ʾʱ��, ��λΪ��
 * @return ʵ�ʵĽ��볤��
 */
size_t ffaudio_decode(void *data, size_t length, double *pts_in_seconds);

/**
 * ����
 * @param time, ָ�����ҵ�ʱ��, ��λΪ��
 */
void ffaudio_seek(double time);

#endif /* __FFAUDIO_CONTEXT_H */
