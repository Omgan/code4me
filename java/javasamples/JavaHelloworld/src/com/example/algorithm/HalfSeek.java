package com.example.algorithm;

/**
 * �۰�������Ҳ�ƶ��ֲ����㷨��������������һ�������������в���ĳһ�ض�Ԫ�ص������㷨��
 * �㷨˼�룺
 *   1.�������̴�������м�Ԫ�ؿ�ʼ������м�Ԫ��������Ҫ���ҵ�Ԫ�أ����������̽�����
 *   2.���ĳһ�ض�Ԫ�ش��ڻ���С���м�Ԫ�أ�����������ڻ�С���м�Ԫ�ص���һ���в��ң�
 *     ���Ҹ���ʼһ�����м�Ԫ�ؿ�ʼ�Ƚϡ������ĳһ��������Ϊ�գ�������Ҳ�����
 * ����:
 * 	���������㷨ÿһ�αȽ϶�ʹ������Χ��Сһ�롣
 * 
 * ʱ�䣺
 * 	2013-03-21
 */
public class HalfSeek {
	
	private static int[] abc = new int[] {9, 8, 7, 6, 5, 4, 3, 2, 1};
	public static void main(String[] argc) {
		int ret = half_seek(abc, 0, 8, 3);
		System.out.print("half_seek ret:" + ret);
	}
	
	public static int half_seek(int arr[], int low, int high, int num) {
		if ((low >= high) && (arr[low] != num))
			return -1;
		
		int mid;
		mid = (low + high) / 2;
		
		if (arr[mid] == num) {
			return mid;
		}
		else if (arr[mid] > num) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
		return half_seek(arr, low, high, num);
	}
}