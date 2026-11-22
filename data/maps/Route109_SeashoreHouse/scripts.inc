Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Chú là chủ của NHÀ BÃI BIỂN.\n"
	.string "Kêu chú là CHÚ BIỂN cũng được!\p"
	.string "Tất cả những gì chú muốn thấy là\n"
	.string "những trận đấu POKéMON nảy lửa.\p"
	.string "Hãy cho chú thấy sự nhiệt huyết của con!\p"
	.string "Nếu mà con đánh bại được hết NHL\n"
	.string "ở đây, chú sẽ có thưởng cho con.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Hãy cho chú thấy trận đánh nảy lửa!\p"
	.string "Chú mở NHÀ BÃI BIỂN này chỉ vì\n"
	.string "như vậy thôi đó!$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Con cực kỳ nóng!\n"
	.string "Những trận đấu nảy lửa!\l"
	.string "Chú đã quá thoả mãn rồi!\p"
	.string "Mấy trận đấu đó quá là mãn nhãn\n"
	.string "đi, nên là chú sẽ cho con,\p"
	.string "6 chai NƯỚC NGỌT!$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Ủa mà, ê, TÚI con đầy rồi.\n"
	.string "Đi bỏ bớt đồ đi, chú chờ.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Mua NƯỚC NGỌT không?\n"
	.string "POKéMON thích lắm đó!\p"
	.string "Chỉ ¥300/chai!\n"
	.string "Mua đi!$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Chú gởi con!$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Không có tiền sao mua.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Không mua hả?\n"
	.string "Vậy cũng hỏi.$"
 
Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Nếu bạn đang kiếm tìm một trận đấu\n"
	.string "ở NHÀ BÃI BIỂN, bạn sẽ không kiếm\l"
	.string "được ai nóng hơn tui đâu, bạn ơi!$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Đúng là một trận đấu nóng hổi!\n"
	.string "Tui chấp nhận thua!$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Mỗi lần tới TP.CẢNG là tui thích\n"
	.string "trận đấu nóng hổi và NƯỚC NGỌT mát lạnh!$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Đừng mắc công đánh mấy trận chán chán.\p"
	.string "Chỉ những trận đấu nảy lửa mới rèn\n"
	.string "luyện nên NHL và POKéMON!$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "Nóng quá!$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Whew, khát nước quá.\n"
	.string "Chắc tui phải làm lon NƯỚC NGỌT quá.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Tui sẽ cho bạn biết sự lợi hại\n"
	.string "của POKéMON, nhưng đừng có khóc nha!$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…Tui thua rồi, tui không có khóc đâu…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Nếu mà POKéMON của tui biết chiêu thức\n"
	.string "để chở tui băng qua bên kia bờ biển,\l"
	.string "thì tui sẽ vục cái phao này.$"

