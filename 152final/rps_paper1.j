.source rps
.class rps_paper1
.super java/lang/Object
.implements java/awt/event/ActionListener

;
; Main class constructor
;
.method public <init>()V
.var 0 is this Lrps_paper1;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

.method public actionPerformed(Ljava/awt/event/ActionEvent;)V
.var 0 is this Lrps_paper1;
.var 1 is e Ljava/awt/event/ActionEvent;
;
; 095 choice=3
;
	iconst_3
	putstatic	rps/choice I
;
; 096 compChoice=random(3)+1
;
	getstatic	rps/_random Ljava/util/Random;
	iconst_3
	invokevirtual	java/util/Random/nextInt(I)I
	iconst_1
	iadd
	putstatic	rps/compchoice I
;
; 097 if(checkWin(choice,compChoice)){score=score+1;win.setText("Win!");}els ...
;
	getstatic	rps/choice I
	getstatic	rps/compchoice I
	invokestatic	rps/checkwin(II)I
	ifeq	L029
;
; 099 score=score+1
;
	getstatic	rps/score I
	iconst_1
	iadd
	putstatic	rps/score I
;
; 100 win.setText("Win!")
;
	getstatic	rps/win Ljavax/swing/JLabel;
	ldc	"Win!"
	invokevirtual	javax/swing/JLabel/setText(Ljava/lang/String;)V
	goto	L030
L029:
;
; 102 if(choice==compchoice){win.setText("Tie!");}else{win.setText("you lost ...
;
	getstatic	rps/choice I
	getstatic	rps/compchoice I
	if_icmpeq	L032
	iconst_0
	goto	L033
L032:
	iconst_1
L033:
	ifeq	L031
;
; 104 win.setText("Tie!")
;
	getstatic	rps/win Ljavax/swing/JLabel;
	ldc	"Tie!"
	invokevirtual	javax/swing/JLabel/setText(Ljava/lang/String;)V
	goto	L034
L031:
;
; 108 win.setText("you lost!")
;
	getstatic	rps/win Ljavax/swing/JLabel;
	ldc	"you lost!"
	invokevirtual	javax/swing/JLabel/setText(Ljava/lang/String;)V
;
; 109 computerScore=computerscore+1;
;
	getstatic	rps/computerscore I
	iconst_1
	iadd
	putstatic	rps/computerscore I
L034:
L030:
;
; 112 if(compChoice==1){choiceLab="Rock";}elseif(compChoice==2){choiceLab="S ...
;
	getstatic	rps/compchoice I
	iconst_1
	if_icmpeq	L036
	iconst_0
	goto	L037
L036:
	iconst_1
L037:
	ifeq	L035
;
; 114 choiceLab="Rock";
;
	ldc	"Rock"
	putstatic	rps/choicelab Ljava/lang/String;
	goto	L038
L035:
;
; 116 if(compChoice==2){choiceLab="Scissors";}elsechoiceLab="Paper"
;
	getstatic	rps/compchoice I
	iconst_2
	if_icmpeq	L040
	iconst_0
	goto	L041
L040:
	iconst_1
L041:
	ifeq	L039
;
; 118 choiceLab="Scissors";
;
	ldc	"Scissors"
	putstatic	rps/choicelab Ljava/lang/String;
	goto	L042
L039:
;
; 121 choiceLab="Paper"
;
	ldc	"Paper"
	putstatic	rps/choicelab Ljava/lang/String;
L042:
L038:
;
; 123 complab.setText("I chose "+choicelab)
;
	getstatic	rps/complab Ljavax/swing/JLabel;
	ldc	"I chose "
	new	java/lang/StringBuilder
	dup_x1
	swap
	invokestatic	java/lang/String/valueOf(Ljava/lang/Object;)Ljava/lang/String;
	invokespecial	java/lang/StringBuilder/<init>(Ljava/lang/String;)V
	getstatic	rps/choicelab Ljava/lang/String;
	invokevirtual	java/lang/StringBuilder/append(Ljava/lang/String;)Ljava/lang/StringBuilder;
	invokevirtual	java/lang/StringBuilder/toString()Ljava/lang/String;
	invokevirtual	javax/swing/JLabel/setText(Ljava/lang/String;)V
;
; 124 compscorel.setText("My score is "+computerscore)
;
	getstatic	rps/compscorel Ljavax/swing/JLabel;
	ldc	"My score is "
	new	java/lang/StringBuilder
	dup_x1
	swap
	invokestatic	java/lang/String/valueOf(Ljava/lang/Object;)Ljava/lang/String;
	invokespecial	java/lang/StringBuilder/<init>(Ljava/lang/String;)V
	getstatic	rps/computerscore I
	invokevirtual	java/lang/StringBuilder/append(I)Ljava/lang/StringBuilder;
	invokevirtual	java/lang/StringBuilder/toString()Ljava/lang/String;
	invokevirtual	javax/swing/JLabel/setText(Ljava/lang/String;)V
;
; 125 scoreL.setText("Your score is "+score)
;
	getstatic	rps/scorel Ljavax/swing/JLabel;
	ldc	"Your score is "
	new	java/lang/StringBuilder
	dup_x1
	swap
	invokestatic	java/lang/String/valueOf(Ljava/lang/Object;)Ljava/lang/String;
	invokespecial	java/lang/StringBuilder/<init>(Ljava/lang/String;)V
	getstatic	rps/score I
	invokevirtual	java/lang/StringBuilder/append(I)Ljava/lang/StringBuilder;
	invokevirtual	java/lang/StringBuilder/toString()Ljava/lang/String;
	invokevirtual	javax/swing/JLabel/setText(Ljava/lang/String;)V
	return
.limit locals 3
.limit stack 7
.end method
