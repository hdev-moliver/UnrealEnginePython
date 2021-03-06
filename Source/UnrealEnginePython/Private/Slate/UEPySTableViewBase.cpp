
#include "UnrealEnginePythonPrivatePCH.h"

#include "UEPySTableViewBase.h"


#define GET_s_table_view_base STableViewBase *s_table_view_base = (STableViewBase *)self->s_compound_widget.s_widget.s_widget

static PyObject *py_ue_stable_view_base_set_item_height(ue_PySTableViewBase *self, PyObject * args) {
	float size;
	if (!PyArg_ParseTuple(args, "f:set_item_height", &size)) {
		return NULL;
	}

	GET_s_table_view_base;

	s_table_view_base->SetItemHeight(size);

	Py_INCREF(self);
	return (PyObject *)self;
}


static PyObject *py_ue_stable_view_base_set_item_width(ue_PySTableViewBase *self, PyObject * args) {
	float size;
	if (!PyArg_ParseTuple(args, "f:set_item_width", &size)) {
		return NULL;
	}

	GET_s_table_view_base;

	s_table_view_base->SetItemWidth(size);

	Py_INCREF(self);
	return (PyObject *)self;
}

static PyObject *ue_PySTableViewBase_str(ue_PySBorder *self)
{
	return PyUnicode_FromFormat("<unreal_engine.STableViewBase '%p'>",
		self->s_compound_widget.s_widget.s_widget);
}

static PyMethodDef ue_PySTableViewBase_methods[] = {
	{ "set_item_height", (PyCFunction)py_ue_stable_view_base_set_item_height, METH_VARARGS, "" },
	{ "set_item_width", (PyCFunction)py_ue_stable_view_base_set_item_width, METH_VARARGS, "" },
	{ NULL }  /* Sentinel */
};

PyTypeObject ue_PySTableViewBaseType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"unreal_engine.STableViewBase", /* tp_name */
	sizeof(ue_PySTableViewBase), /* tp_basicsize */
	0,                         /* tp_itemsize */
	0,       /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,                         /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)ue_PySTableViewBase_str,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,        /* tp_flags */
	"Unreal Engine STableViewBase",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	0,                         /* tp_iternext */
	ue_PySTableViewBase_methods,             /* tp_methods */
};

void ue_python_init_stable_view_base(PyObject *ue_module) {
	ue_PySTableViewBaseType.tp_new = PyType_GenericNew;

	ue_PySTableViewBaseType.tp_base = &ue_PySCompoundWidgetType;

	if (PyType_Ready(&ue_PySBorderType) < 0)
		return;

	Py_INCREF(&ue_PySTableViewBaseType);
	PyModule_AddObject(ue_module, "STableViewBase", (PyObject *)&ue_PySTableViewBaseType);
}
