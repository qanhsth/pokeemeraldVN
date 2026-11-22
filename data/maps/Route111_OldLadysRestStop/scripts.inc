Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Trời, con ơi con.\n"
	.string "POKéMON của con mệt lắm đúng không?\p"
	.string "Nếu con thích thì cho tụi nó nghỉ xíu đi.\n"
	.string "Ngoại thấy được đó! Con nên làm vậy đi.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "Đúng rồi.\n"
	.string "Cứ thoải mái, thư giãn đi con!$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Trời, con ơi con.\n"
	.string "POKéMON của con còn mệt không?\p"
	.string "Nếu còn thì nghỉ thêm cái nữa đi.\n"
	.string "Ngoại thấy được đó. Con nên làm vậy đi.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "Vậy hả?\n"
	.string "Con không cần phải ngại đâu.$"

