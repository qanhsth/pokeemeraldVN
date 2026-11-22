Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Bạn nói gì?\n"
	.string "Tui đang làm gì á hả?\p"
	.string "Tui đang tính làm cái phòng ở đây\n"
	.string "bằng cách sử dụng chiêu của POKéMON.\p"
	.string "Biết rồi! Tui sẽ cho bạn cái TM này.\n"
	.string "Bạn sẽ xài nó để làm phòng cho mình chứ?$"

Route111_Text_ExplainSecretPower:
	.string "Kiếm 1 cái cây bự mà có\n"
	.string "rớt mấy cọng dây leo xuống.\p"
	.string "Sử dụng LỰC BÍ ẨN trước cái cây.\n"
	.string "Mấy cọng dây leo sẽ rớt xuống,\l"
	.string "rồi bạn sẽ có thể leo lên cây.\p"
	.string "Bạn sẽ có được 1 cái chỗ\n"
	.string "cho bạn để đồ bạn thích.\p"
	.string "Nó sẽ là căn phòng bí mật…\n"
	.string "CĂN CỨ BÍ MẬT!\p"
	.string "Bạn nên làm thử 1 cái đi.\p"
	.string "Còn nữa, bạn không chỉ làm được\n"
	.string "CĂN CỨ BÍ MẬT ở trên cây thôi đâu.\p"
	.string "Thử xài LỰC BÍ ẨN lên cái tường\n"
	.string "mà có lỗ nhỏ đi.\p"
	.string "Thôi tui đi kiếm chỗ khác đây.\n"
	.string "Bai nha!$"

Route111_Text_DontWantThis:
	.string "Ủa không thích hả?\n"
	.string "Nếu mà đổi ý, thì cho tui hay nha?$"

Route111_Text_DontHaveAnyRoom:
	.string "Ủa hết chỗ để rồi.\p"
	.string "Vậy giờ tui cầm giùm cho,\n"
	.string "lát nữa quay lại lấy nha?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
