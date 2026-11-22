LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Tui là người THIẾT KẾ GAME.\p"
	.string "Ủa, vậy hả?\n" 
	.string "Bạn đang làm DS.POKéMON hả?\p"
	.string "Hơi khó để hoàn thiện hết,\n"
	.string "mà cố lên, đừng bỏ cuộc.\p"
	.string "Nếu hoàn thiện xong, hãy\n"
	.string "đem lại cho tui coi.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Trời! Hay quá vậy!\n"
	.string "Ừa, quá ghê luôn!\p"
	.string "Cái DS.POKéMON này đầy đủ hết rồi!\n"
	.string "Chắc bạn yêu quý POKéMON lắm!\p"
	.string "Ngưỡng mộ quá!\p"
	.string "Để tui gởi bạn một món quà\n"
    .string "để ghi nhận thành tích!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Tui hả? Bạn nói tui á hả?\n"
	.string "Tui là người LẬP TRÌNH.\p"
	.string "Không biết MÁY 3 SỐ\n"
	.string "ở đây ra sao nữa.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Tui là người THIẾT KẾ ĐỒ HOẠ!\n"
	.string "POKéMON vùng HOENN thú vị ha?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Mấy em TUBER, nhìn dễ thương ha?\n"
	.string "Được thách đấu với một em TUBER…\p"
	.string "Ờm, đã lắm!\p"
	.string "Với SINH ĐÔI! Cũng dễ thương mà ha?\n"
	.string "Đấu trận 2v2 với cặp SINH ĐÔI…\p"
	.string "Ờm, vui lắm á!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "Gió biển thổi vào tâm hồn tôi.\n"
	.string "Cảm giác thật tuyệt vời!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "Bạn sẽ không biết được ở đâu, hay\n"
    .string "khi nào có người thách đấu mình.\p"
    .string "Bởi vậy nên tui đi ra ngoài, lúc\n"
    .string "nào cũng đem theo GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "SƠN: … … … … …\n"
	.string "… … … … … Khò khò…\p"
	.string "… … … … … Hở?!\n"
	.string "Ủa, xin lỗi nha! Mới chợp mắt xíu!\p"
	.string "Chú tới để coi thử cái\n"
	.string "CUỘC THI POKéMON.\p"
	.string "Phải công nhận là, nhìn\n"
	.string "cũng vui, nhưng mà…\p"
	.string "Là người theo chủ nghĩa thuần tuý,\n"
	.string "chú chỉ thích trận đấu với NHL mạnh.\p"
	.string "Chú là người vậy đó.\p"
	.string "{PLAYER} ơi, chú mong là con sẽ tận\n"
	.string "hưởng đủ loại NHÀ THI ĐẤU, THI HOA HẬU,\l"
	.string "HỘI THI ĐẤU, tất cả mọi thứ luôn!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SƠN: Chú nghĩ là phải có chiến\n"
	.string "thuật mới thắng được CUỘC THI.\p"
	.string "Có thể nói, nghiên cứu trước chiến\n"
	.string "thuật cũng là một cách để giỏi hơn.$"

