RustboroCity_Flat2_2F_MapScripts::
	.byte 0

RustboroCity_Flat2_2F_EventScript_OldMan::
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
	release
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall::
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays:
	.string "Hồi xửa hồi xưa, DEVON\n"
	.string "chỉ là một công ty nhỏ xíu mà thôi.$"

RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt:
	.string "Ba tui đang làm ở TẬP ĐOÀN đó.\p"
	.string "Ba tui làm ra cái này nè!\n"
	.string "Mà giờ tui hong có xài được, thôi cho nè.$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo:
	.string "Ba tui đang làm ở TẬP ĐOÀN đó.\p"
	.string "Lớn lên tui cũng muốn\n"
	.string "được làm ở DEVON.$"

