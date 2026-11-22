MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Woohoo!\p"
	.string "Người ta hay kêu tui là THẰNG ĐẬP ĐÁ,\n"
	.string "nhưng mà cách gọi đó hơi hạ thấp tui.\p"
	.string "Tui xứng đáng được tôn trọng hơn,\n"
	.string "như là ÔNG ĐẬP ĐÁ chẳng hạn.\p"
	.string "Woohoo!\p"
	.string "Dù gì thì POKéMON cũng\n"
	.string "mạnh đó.\p"
	.string "Tui rất thích!\n"
	.string "Nè, cầm lấy MÁY HỌC CHIÊU ẨN này đi!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "HM đó chứa ĐẬP ĐÁ.\p"
	.string "Nếu bạn thấy tảng đá\n"
	.string "cản đường bạn…\p"
	.string "Thì hãy xài cái chiêu HM này\n"
	.string "để đập bể nó, rồi đi tiếp!\p"
	.string "Đúng vậy thưa ngài! Đập bể luôn!\n"
	.string "Woohoo!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "À đúng rồi, nếu bạn đập bể đá,\n"
	.string "POKéMON núp trong đó có thể nhảy ra đó.\p"
	.string "Woohoo!$"

