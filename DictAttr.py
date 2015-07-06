class DictAttr(dict):
	"""Allows to access to dictionnary elements like to attributes of structure"""
	__getattr__ = dict.__getitem__
	__setattr__ = dict.__setitem__
	def __init__(self, *args, **kwargs):
		super(DictAttr, self).__init__(dict.fromkeys(args), **kwargs)