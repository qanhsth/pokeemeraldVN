SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "NÚI TIỄN ĐƯA…\p"
	.string "Ở trên đỉnh, có 2 viên ngọc\n"
	.string "để ở 2 bên. Con có biết không?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Đúng rồi, 2 viên ngọc ở 2 bên…\p"
	.string "Ngắm nhìn tụi nó ở bên nhau…\n"
	.string "Cảm giác cứ nhẹ lòng sao á…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Ủa vậy hả?\n"
	.string "Vậy con cũng nên tới coi thử đi…$"

