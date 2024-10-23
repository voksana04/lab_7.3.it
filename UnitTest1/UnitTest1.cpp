#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\admin\source\repos\Project_7.3_it\Project_7.3_it\lab_7.3_it.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int rowCount = 3;
			const int colCount = 3;

			// ��������� �� ���������� ������� ������� 3x3
			int** testMatrix = new int* [rowCount];
			for (int i = 0; i < rowCount; i++)
				testMatrix[i] = new int[colCount];

			// ������� ��� �������� �������� � 2-� ������
			testMatrix[0][0] = 1; testMatrix[0][1] = 2; testMatrix[0][2] = 3;
			testMatrix[1][0] = 0; testMatrix[1][1] = 5; testMatrix[1][2] = 6;
			testMatrix[2][0] = 7; testMatrix[2][1] = 8; testMatrix[2][2] = 9;

			// ��������� ������� CountRowsWithoutZero
			int rowsWithoutZero = CountRowsWithoutZero(testMatrix, rowCount, colCount);

			// ������� 2 ����� ��� �������� �������� (����� 0 � 2)
			Assert::AreEqual(2, rowsWithoutZero);

			// ��������� ���'���
			for (int i = 0; i < rowCount; i++)
				delete[] testMatrix[i];
			delete[] testMatrix;
		}
	};
}
