MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "Không khí âm u của ngọn núi\n"
	.string "đã làm tăng bật sức mạnh ma quái!\p"
	.string "Nhóc con mới lớn…\n"
	.string "Đòi thắng được ta?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "Ta tự thương hại mình…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "Sức mạnh ma quái của ta\n"
	.string "lẽ ra đã tăng vọt lên, vậy mà…$"

MtPyre_3F_Text_KaylaIntro:
	.string "Ahahahaha!\p"
	.string "Đây không phải là chỗ để chơi,\n"
    .string "nhất là đứa con nít như ngươi!$"

MtPyre_3F_Text_KaylaDefeat:
    .string "Ta đã thua trắng tay…$"

MtPyre_3F_Text_KaylaPostBattle:
    .string "Điều này có nghĩa là ta chưa\n"
    .string "rèn luyện đủ…\p"
    .string "Ta phải tiếp tục nỗ lực hướng tới\n"
    .string "đỉnh cao…\p"
    .string "Cố lên, bản thân ta ơi!$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Tới đây chi?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "Trận đánh rất hay!\n"
	.string "Bạn đúng là NHL tài năng.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "POKéMON không còn trên cõi đời.\n"
	.string "Mấy con đi theo bạn hiện giờ.\p"
	.string "Với mấy con mà bạn sẽ\n"
	.string "gặp ở tương lai…\p"
	.string "Hãy yêu quý lấy tụi nó.\n"
	.string "Xin đừng quên điều đó.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "Tui muốn được thấy POKéMON\n"
	.string "của bạn khi tụi nó lớn lên…\p"
	.string "Làm ơn, cho tui xin số đi.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Ủa, là bạn sao…\p"
	.string "Bạn tới để cho tui coi\n"
	.string "POKéMON đã lớn của mình sao?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "Tuyệt vời!\n"
	.string "Bạn là người được chọn.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "POKéMON không còn trên cõi đời.\n"
	.string "Mấy con đi theo bạn hiện giờ.\p"
	.string "Với mấy con mà bạn sẽ\n"
	.string "gặp ở tương lai…\p"
	.string "Hãy yêu quý lấy tụi nó.\n"
	.string "Vậy là bạn đã không quên điều đó.$"

