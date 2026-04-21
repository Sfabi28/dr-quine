# comment
FILENAME = 'Grace_kid.py'
SOURCE = '# comment\nFILENAME = %r\nSOURCE = %r\nwith open(FILENAME, "w") as f:\n\tf.write(SOURCE %% (FILENAME, SOURCE))\n'
with open(FILENAME, "w") as f:
	f.write(SOURCE % (FILENAME, SOURCE))
