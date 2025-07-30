// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from robot_ras_decision:msg/Movement.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "robot_ras_decision/msg/detail/movement__struct.h"
#include "robot_ras_decision/msg/detail/movement__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool robot_ras_decision__msg__movement__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("robot_ras_decision.msg._movement.Movement", full_classname_dest, 41) == 0);
  }
  robot_ras_decision__msg__Movement * ros_message = _ros_message;
  {  // direcao
    PyObject * field = PyObject_GetAttrString(_pymsg, "direcao");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->direcao, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // distancia
    PyObject * field = PyObject_GetAttrString(_pymsg, "distancia");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->distancia = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // angulo
    PyObject * field = PyObject_GetAttrString(_pymsg, "angulo");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->angulo = (float)PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * robot_ras_decision__msg__movement__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Movement */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("robot_ras_decision.msg._movement");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Movement");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  robot_ras_decision__msg__Movement * ros_message = (robot_ras_decision__msg__Movement *)raw_ros_message;
  {  // direcao
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->direcao.data,
      strlen(ros_message->direcao.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "direcao", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // distancia
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->distancia);
    {
      int rc = PyObject_SetAttrString(_pymessage, "distancia", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // angulo
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->angulo);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angulo", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
