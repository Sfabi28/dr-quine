# outside main

def function():
	source = '# outside main\n\ndef function():\n\tsource = %r\n\tprint(source %% source)\n\nif __name__ == "__main__":\n\t# inside main\n\tfunction()'
	print(source % source)

if __name__ == "__main__":
	# inside main
	function()
