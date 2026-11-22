SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Ừm… Nếu cái này để ở đây, còn\n"
    .string "cái đó để ở đằng kia…\p"
    .string "Vậy thì cái này để đâu?\n"
    .string "Còn cái đồ lặt vặt kia thì sao?\p"
    .string "Aaargh! Không biết làm sao\n"
    .string "để cái này sao nữa!$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hửm?\n"
	.string "Chào, tui là ĐẬU.\p"
	.string "THUYỀN TRƯỞNG SANG điều tui tới\n"
	.string "để thiết kế con tàu.\p"
	.string "Ủa! Cái đó…\n"
	.string "TÚI DEVON phải không?\p"
	.string "Mà, hmm…\n"
	.string "Không được rồi…\p"
	.string "THUYỀN TRƯỞNG SANG đi đâu mất tiêu rồi.\n"
	.string "Ổng nói có chuyện cần làm.\p"
	.string "Bạn đi kiếm THUYỀN TRƯỞNG SANG rồi\n"
	.string "đưa cái đó cho ổng giùm tui được không?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "ĐẬU: THUYỀN TRƯỞNG SANG\n"
	.string "đi đâu vậy trời?\p"
	.string "Bạn đi kiếm THUYỀN TRƯỞNG SANG rồi\n"
	.string "đưa cái đó cho ổng giùm tui được không?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "ĐẬU: Đóng tàu là một nghệ thuật.\p"
    .string "Có rất nhiều cái không thể tìm ra\n"
    .string "chỉ bằng cách tính toán.\p"
    .string "Tui thực sự cần lời khuyên từ một người\n"
    .string "có kinh nghiệm và am hiểu về biển cả…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "ĐẬU: Chào! ÔNG THU cũng tới đây\n"
	.string "để phụ tụi tui nữa.\p"
	.string "Nhờ có ông cựu thuỷ thủ, mà con\n"
	.string "tàu sắp được hoàn thiện rồi.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "ĐẬU: Con tàu đã được đóng xong!\p"
    .string "Con tàu S.S. TIDAL thực sự là một\n"
    .string "kỳ quan của công nghệ!\p"
	.string "Nhưng, tôi có cảm giác là tụi mình còn\n"
    .string "tạo ra được cái gì đó còn đỉnh hơn nữa.\p"
    .string "Bạn cũng biết mà, sự tiến bộ của\n"
    .string "công nghệ là vô tận.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "ÔNG THU: Ah, {PLAYER}!\n"
	.string "Cũng lâu rồi ha!\p"
    .string "Ừ, từ khi gặp con, lão thủy thủ già này\n"
    .string "mới cảm thấy tràn đầy sức sống!\p"
	.string "Cho nên ông mới quyết định giúp ĐẬU\n"
    .string "chế một con tàu.\p"
    .string "Ừ, suy cho cùng, con tàu có thể\n"
    .string "chở được rất nhiều người.\p"
    .string "Nhưng mà, con cũng biết, ĐẬU thực sự\n"
    .string "là một người đặc biệt.\p"
	.string "Với tài năng về công nghệ của nó và\n"
    .string "kinh nghiệm của ông, chắc chắn sẽ\l"
    .string "đóng được 1 con tàu tuyệt vời, đúng vậy!$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Mùa màng, thời tiết, nơi\n"
    .string "mặt trăng lơ lửng trên bầu trời…\p"
    .string "Các yếu tố này phối hợp với nhau\n"
    .string "làm cho biển thay đổi diện mạo.\p"
    .string "Đúng vậy!\n"
    .string "Biển giống như một sinh vật sống!$"	

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Tui dễ bị say sóng.\n"
	.string "Nên là tui mới đổi qua đây làm.$"

