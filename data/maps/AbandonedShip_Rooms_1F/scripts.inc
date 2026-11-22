AbandonedShip_Rooms_1F_MapScripts::
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_DEMETRIUS, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Loại tàu này rất hiếm, nên tui\n"
    .string "đang nhìn ngó xung quanh một chút.\p"
    .string "Hừm hừm…\n"
    .string "Có vẻ như còn có cabin khác nữa…$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Sao bạn lại tới đây?\n"
	.string "Tò mò lắm hả!$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Không chỉ tò mò, mà còn mạnh nữa…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "Cái ông phòng kế bên…\p"
	.string "Ổng kêu ổng chỉ qua ngắm cảnh thôi,\n"
	.string "mà có cảnh gì đâu mà ngắm.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Bạn đúng là NHL mạnh mẽ!\n"
	.string "Tui sẽ lưu số bạn làm kỷ niệm!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Sao bạn quay lại đây chi nữa?\n"
	.string "Tò mò lắm rồi hả!$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Có mạnh quá không vậy?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Chắc cái ông đó tính làm gì đó rồi!\n"
	.string "Nhìn ổng cứ sao sao á!$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Waaah!\n"
	.string "Được thấy rồi! …Hở?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Ủa, bạn không phải mẹ tui.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "Tui đang cãi lộn với mẹ, nên chạy trốn.\n"
	.string "Đừng nói ai biết, tui ở đây nha!$"

