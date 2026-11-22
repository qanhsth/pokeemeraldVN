MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	pokemartlistend

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "HỒI SỨC đã lắm!\p"
	.string "Đưa cho POKéMON bị xỉu,\n"
	.string "và POKéMON đó sẽ tỉnh lại.\p"
	.string "Nhưng mà nhớ là, HỒI SỨC không có\n"
	.string "hồi lại PP chiêu thức đâu nha.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "XUA ĐUỔI++ giúp đuổi POKéMON yếu đi.\p"
	.string "Hơn mọi loại XUA ĐUỔI khác,\n"
	.string "hiệu lực của nó là lâu nhất.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "CẦU LƯỚI với CẦU NƯỚC đều là QUẢ\n"
	.string "CẦU POKéMON chỉ được làm ở XANH RÊU.\p"
	.string "CẦU LƯỚI hiệu quả với\n"
	.string "POKéMON hệ BỌ với hệ NƯỚC.\p"
	.string "CẦU NƯỚC sẽ tốt hơn cho\n"
	.string "POKéMON dưới đáy biển.$"

