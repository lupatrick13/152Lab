.source rps
.class rps_rock1
.super java/lang/Object
.implements java/awt/event/ActionListener

;
; Main class constructor
;
.method public <init>()V
.var 0 is this Lrps_rock1;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

.method public actionPerformed(Ljava/awt/event/ActionEvent;)V
.var 0 is this Lrps_rock1;
.var 1 is e Ljava/awt/event/ActionEvent;
;
; 029 choice=1
;
	iconst_1
	putstatic	rps/choice I
;
; 030 compChoice=random(3)+1
;
	getstatic	rps/_random Ljava/util/Random;
	iconst_3
	invokevirtual	java/util/Random/nextInt(I)I
	iconst_1
	iadd
	putstatic	rps/compchoice I
;
; 031 if(checkWin(choice,compChoice)){score=score+1;win.setText("Win!");}els ...
;
	getstatic	rps/choice I
	getstatic	rps/compchoice I
	invokestatic	rps/checkwin(II)I
	ifeq	L001
;
; 033 score=score+1
;
	getstatic	rps/score I
	iconst_1
	iadd
	putstatic	rps/score I
;
; 034 win.setText("Win!")
;
	getstatic	rps/win Ljavax/swing/JLabel;
	ldc	"Win!"
	invokevirtual	javax/swing/JLabel/setText(Ljava/lang/String;)V
	goto	L002
L001:
;
; 036 if(choice==compchoice){win.setText("Tie!");}else{win.setText("you lost ...
;
	getstatic	rps/choice I
	getstatic	rps/compchoice I
	if_icmpeq	L004
	iconst_0
	goto	L005
L004:
	iconst_1
L005:
	ifeq	L003
;
; 038 win.setText("Tie!")
;
	getstatic	rps/win Ljavax/swing/JLabel;
	ldc	"Tie!"
	invokevirtual	javax/swing/JLabel/setText(Ljava/lang/String;)V
	goto	L006
L003:
;
; 042 win.setText("you lost!")
;
	getstatic	rps/win Ljavax/swing/JLabel;
	ldc	"you lost!"
	invokevirtual	javax/swing/JLabel/setText(Ljava/lang/String;)V
;
; 043 computerScore=computerscore+1;
;
	getstatic	rps/computerscore I
	iconst_1
	iadd
	putstatic	rps/computerscore I
L006:
L002:
;
; 047 if(compChoice==1){choiceLab="Rock";}elseif(compChoice==2){choiceLab="S ...
;
	getstatic	rps/compchoice I
	iconst_1
	if_icmpeq	L008
	iconst_0
	goto	L009
L008:
	iconst_1
L009:
	ifeq	L007
;
; 049 choiceLab="Rock";
;
	ldc	"Rock"
	putstatic	rps/choicelab Ljava/lang/String;
	goto	L010
L007:
;
; 051 if(compChoice==2){choiceLab="Scissors";}elsechoiceLab="Paper"
;
	getstatic	rps/compchoice I
	iconst_2
	if_icmpeq	L012
	iconst_0
	goto	L013
L012:
	iconst_1
L013:
	ifeq	L011
;
; 053 choiceLab="Scissors";
;
	ldc	"Scissors"
	putstatic	rps/choicelab Ljava/lang/String;
	goto	L014
L011:
;
; 056 choiceLab="Paper"
;
	ldc	"Paper"
	putstatic	rps/choicelab Ljava/lang/String;
L014:
L010:
;
; 057 scoreL.setText("Your score is "+score)
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
;
; 058 compscorel.setText("My score is "+computerscore)
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
; 059 complab.setText("I chose "+choiceLab)
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
	return
.limit locals 3
.limit stack 7
.end method
