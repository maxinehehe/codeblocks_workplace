#include <iostream>
#include <python2.7/Python.h>
#include<python.h>
using namespace std;

int main()
{
    Py_Initialize();//≥ı ºªØ

  PyObject* pModule = NULL;
  PyObject* pFunc = NULL;
  PyObject* pParam = NULL;
  PyObject* pResult = NULL;
  const char* pBuffer = NULL;
  int iBufferSize = 0;
    cout << "Hello world!" << endl;
    return 0;
}
