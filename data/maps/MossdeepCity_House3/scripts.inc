MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Ê, cái NHL kia!\n"
	.string "CẦN CÂU XỊN xài đã lắm đó!\p"
	.string "Bạn nói gì kệ bạn, mà cái cần này\n"
	.string "bắt được POKéMON dưới đáy biển luôn!\p"
	.string "Bạn nghĩ sao?\n"
	.string "Thích không?$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Ừa, ừa đúng rồi đó!\n"
	.string "Sau cùng thì CẦN CÂU XỊN là nhất!$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "Nếu thấy chỗ nào có nước, thử thả\n"
	.string "CẦN xuống coi có con nào cắn không!$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hả?\n"
	.string "Không thích câu cá hả?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Theo kịp POKéMON dưới đáy biển\n"
	.string "bằng cái CẦN CÂU XỊN đi.$"
