MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Mọi loài sinh vật đều lang thang\n"
    .string "bên sườn NÚI TIỄN ĐƯA…\p"
    .string "Ai mà biết được chuyện gì sẽ xảy ra.\n"
    .string "Cầm đi. Để phòng xui rủi.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Cho POKéMON cầm cái\n"
	.string "BÙA TẨY.\p"
	.string "Sẽ đỡ gặp POKéMON hoang hơn.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Bạn tới đây để viếng linh hồn\n"
    .string "của POKéMON đã khuất sao?\p"
    .string "Chắc bạn thương POKéMON của mình lắm.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "Đây là nơi an nghỉ của\n"
	.string "ZIGZAGOON. Tui nhớ nó quá…$"

