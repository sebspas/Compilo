opcode = \
	{ "NOP": 0
	, "ADD": 1
	, "MUL": 2
	, "SUB": 3
	, "DIV": 4
	, "COP": 5
	, "AFC": 6
	, "LOAD": 7
	, "STORE": 8
	, "EQU": 9
	, "INF": 10
	, "INFE": 11
	, "SUP": 12
	, "SUPE": 13
	, "JMP": 14
	, "JMPC": 15
	, "JMPR": 16
	, "OR": 17
	, "AND": 18
	, "NEG": 19
	, "PRI": 20
	}

lines = open("asm.txt", "r").readlines()

for line in lines:
	line = line.strip()
	fields = line.split("	")
	fields = [ x.strip() for x in fields ]
	if fields[0] == "NOP": #OP null null
		print "%02x%FFxFF" % (opcode[fields[0]])
	elif fields[0] in ("ADD", "MUL", "SUB", "DIV", "COP", "INF", "INFE", "SUP", "SUPE", "EQU"): # OP R R
		print "%02x%02x%02xFF" % (opcode[fields[0]], int(fields[1]), int(fields[2]))
	elif fields[0] in ("AFC","LOAD"): #OP R VAL/@a
		print "%02x%02x%04x" % (opcode[fields[0]], int(fields[1]), int(fields[2]))
	elif fields[0] in ("STORE", "JMPC"): #OP @a R
		print "%02x%04x%02x" % (opcode[fields[0]], int(fields[1]), int(fields[2]))
	elif fields[0] == "JMP": #OP @a
		print "%02x%04xFF" % (opcode[fields[0]], int(fields[1]))
	elif fields[0] in ("JMPR", "NEG"): #OP R null
		print "%02x%02xFFFF" % (opcode[fields[0]], int(fields[1]))
	else:
		print "not handled"
