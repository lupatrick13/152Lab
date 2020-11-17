.source rps
.class rps_scissor1
.super java/lang/Object
.implements java/awt/event/ActionListener

;
; Main class constructor
;
.method public <init>()V
.var 0 is this Lrps_scissor1;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

.method public actionPerformed(Ljava/awt/event/ActionEvent;)V
.var 0 is this Lrps_scissor1;
.var 1 is e Ljava/awt/event/ActionEvent;
;
; 062 choice=2
;
	iconst_2
	putstatic	rps/choice I
;
; 063 compChoice=random(3)+1
;
	getstatic	rps/_random Ljava/util/Random;
	iconst_3
	invokevirtual	java/util/Random/nextInt(I)I
	iconst_1
	iadd
	putstatic	rps/compchoice I
;
; 064 if(checkWin(choice,compChoice)){score=score+1;win.setText("Win!");}els ...
;
	getstatic	rps/choice I
	getstatic	rps/compchoice I
	invokestatic	rps/checkwin(II)I
	ifeq	L015
;
; 066 score=score+1
;
	getstatic	rps/score I
	iconst_1
	iadd
	putstatic	rps/score I
;
; 067 win.setText("Win!")
;
	getstatic	rps/win Ljavax/swing/JLabel;
	ldc	"Win!"
	invokevirtual	javax/swing/JLabel/setText(Ljava/lang/String;)V
	goto	L016
L015:
;
; 069 if(choice==compchoice){win.setText("Tie!");}else{win.setText("you lost ...
;
	getstatic	rps/choice I
	getstatic	rps/compchoice I
	if_icmpeq	L018
	iconst_0
	goto	L019
L018:
	iconst_1
L019:
	ifeq	L017
;
; 071 win.setText("Tie!")
;
	getstatic	rps/win Ljavax/swing/JLabel;
	ldc	"Tie!"
	invokevirtual	javax/swing/JLabel/setText(Ljava/lang/String;)V
	goto	L020
L017:
;
; 075 win.setText("you lost!")
;
	getstatic	rps/win Ljavax/swing/JLabel;
	ldc	"you lost!"
	invokevirtual	javax/swing/JLabel/setText(Ljava/lang/String;)V
;
; 076 computerScore=computerscore+1;
;
	getstatic	rps/computerscore I
	iconst_1
	iadd
	putstatic	rps/computerscore I
L020:
L016:
;
; 079 if(compChoice==1){choiceLab="Rock";}elseif(compChoice==2){choiceLab="S ...
;
	getstatic	rps/compchoice I
	iconst_1
	if_icmpeq	L022
	iconst_0
	goto	L023
L022:
	iconst_1
L023:
	ifeq	L021
;
; 081 choiceLab="Rock";
;
	ldc	"Rock"
	putstatic	rps/choicelab Ljava/lang/String;
	goto	L024
L021:
;
; 083 if(compChoice==2){choiceLab="Scissors";}elsechoiceLab="Paper"
;
	getstatic	rps/compchoice I
	iconst_2
	if_icmpeq	L026
	iconst_0
	goto	L027
L026:
	iconst_1
L027:
	ifeq	L025
;
; 085 choiceLab="Scissors";
;
	ldc	"Scissors"
	putstatic	rps/choicelab Ljava/lang/String;
	goto	L028
L025:
;
; 088 choiceLab="Paper"
;
	ldc	"Paper"
	putstatic	rps/choicelab Ljava/lang/String;
L028:
L024:
;
; 089 scoreL.setText("Your score is "+score)
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
; 090 compscorel.setText("My score is "+computerscore)
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
; 091 complab.setText("I chose "+choiceLab)
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
