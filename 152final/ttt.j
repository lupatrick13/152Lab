.source ttt
.class public ttt
.super java/lang/Object
.field private static _mainframe Ljavax/swing/JFrame;

.field private static _sysin Ljava/util/Scanner;
.field protected static _random Ljava/util/Random;
.field protected static board [[Ljavax/swing/JButton;
.field protected static i I
.field protected static j I
.field protected static pos [Ljava/lang/String;
.field protected static upan [Ljavax/swing/JPanel;

;
; Runtime input scanner
;
.method static <clinit>()V

	new	java/util/Scanner
	dup
	getstatic	java/lang/System/in Ljava/io/InputStream;
	invokespecial	java/util/Scanner/<init>(Ljava/io/InputStream;)V
	putstatic	ttt/_sysin Ljava/util/Scanner;
	new	java/util/Random
	dup
	invokespecial	java/util/Random/<init>()V
	putstatic	ttt/_random Ljava/util/Random;

	new	javax/swing/JFrame
	dup
	ldc	"ttt"
	invokespecial	javax/swing/JFrame/<init>(Ljava/lang/String;)V
	dup
	putstatic	ttt/_mainframe Ljavax/swing/JFrame;
	getstatic	javax/swing/JFrame/EXIT_ON_CLOSE I
	invokevirtual	javax/swing/JFrame/setDefaultCloseOperation(I)V
	return

.limit locals 0
.limit stack 3
.end method

;
; Main class constructor
;
.method public <init>()V
.var 0 is this Lttt;

	aload_0
	invokespecial	java/lang/Object/<init>()V
	return

.limit locals 1
.limit stack 1
.end method

;
; MAIN
;
.method public static main([Ljava/lang/String;)V
.var 0 is args [Ljava/lang/String;
.var 1 is _start Ljava/time/Instant;
.var 2 is _end Ljava/time/Instant;
.var 3 is _elapsed J

	invokestatic	java/time/Instant/now()Ljava/time/Instant;
	astore_1

	iconst_3
	iconst_3
	multianewarray	[[Ljavax/swing/JButton; 2
	putstatic	ttt/board [[Ljavax/swing/JButton;

	iconst_3
	anewarray	java/lang/String
	putstatic	ttt/pos [Ljava/lang/String;

	iconst_3
	newarray	javax/swing/JPanel
	putstatic	ttt/upan [Ljavax/swing/JPanel;

;
; 009 pos[0]="North"
;
	ldc	"North"
	getstatic	ttt/pos [Ljava/lang/String;
;
; 010 pos[1]="South"
;
	ldc	"South"
	getstatic	ttt/pos [Ljava/lang/String;
;
; 011 pos[2]="Center"
;
	ldc	"Center"
	getstatic	ttt/pos [Ljava/lang/String;
;
; 012 i=3
;
	iconst_3
	putstatic	ttt/i I
;
; 013 for(i=0to3){upan[i].create();for(j=0to3){board[i][j].create("at: "+i+" ...
;
	iconst_0
	putstatic	ttt/i I
L002:
	getstatic	ttt/i I
	iconst_3
	if_icmpgt	L003
	iconst_0
	goto	L004
L003:
	iconst_1
L004:
	ifne	L001
;
; 015 upan[i].create()
;

	new	javax/swing/JPanel
	dup
	new	java/awt/BorderLayout
	dup
	invokespecial	java/awt/BorderLayout/<init>()V
	invokespecial	javax/swing/JPanel/<init>(Ljava/awt/LayoutManager;)V
	dup
	bipush	5
	bipush	5
	bipush	5
	bipush	5
	invokestatic	javax/swing/BorderFactory/createEmptyBorder(IIII)Ljavax/swing/border/Border;
	invokevirtual	javax/swing/JPanel/setBorder(Ljavax/swing/border/Border;)V
	getstatic	ttt/upan [Ljavax/swing/JPanel;
	getstatic	ttt/i I
	aaload
	aastore
;
; 016 for(j=0to3){board[i][j].create("at: "+i+"+"+j);upan[i].add(board[i][j] ...
;
	iconst_0
	putstatic	ttt/j I
L006:
	getstatic	ttt/j I
	iconst_3
	if_icmpgt	L007
	iconst_0
	goto	L008
L007:
	iconst_1
L008:
	ifne	L005
;
; 018 board[i][j].create("at: "+i+"+"+j)
;

	new	javax/swing/JButton
	dup
	ldc	"at: "
	new	java/lang/StringBuilder
	dup_x1
	swap
	invokestatic	java/lang/String/valueOf(Ljava/lang/Object;)Ljava/lang/String;
	invokespecial	java/lang/StringBuilder/<init>(Ljava/lang/String;)V
	getstatic	ttt/i I
	invokevirtual	java/lang/StringBuilder/append(I)Ljava/lang/StringBuilder;
	invokevirtual	java/lang/StringBuilder/toString()Ljava/lang/String;
	new	java/lang/StringBuilder
	dup_x1
	swap
	invokestatic	java/lang/String/valueOf(Ljava/lang/Object;)Ljava/lang/String;
	invokespecial	java/lang/StringBuilder/<init>(Ljava/lang/String;)V
	bipush	43
	invokevirtual	java/lang/StringBuilder/append(C)Ljava/lang/StringBuilder;
	invokevirtual	java/lang/StringBuilder/toString()Ljava/lang/String;
	new	java/lang/StringBuilder
	dup_x1
	swap
	invokestatic	java/lang/String/valueOf(Ljava/lang/Object;)Ljava/lang/String;
	invokespecial	java/lang/StringBuilder/<init>(Ljava/lang/String;)V
	getstatic	ttt/j I
	invokevirtual	java/lang/StringBuilder/append(I)Ljava/lang/StringBuilder;
	invokevirtual	java/lang/StringBuilder/toString()Ljava/lang/String;
	invokespecial	javax/swing/JButton/<init>(Ljava/lang/String;)V
	getstatic	ttt/board [[Ljavax/swing/JButton;
	getstatic	ttt/i I
	aaload
	getstatic	ttt/j I
	aaload
	aastore
;
; 019 upan[i].add(board[i][j],pos[j])
;

	getstatic	ttt/upan [Ljavax/swing/JPanel;
	getstatic	ttt/i I
	aaload
	getstatic	ttt/board [[Ljavax/swing/JButton;
	getstatic	ttt/i I
	aaload
	getstatic	ttt/j I
	aaload
	getstatic	ttt/pos [Ljava/lang/String;
	getstatic	ttt/j I
	aaload
	invokevirtual	[Ljavax/swing/JPanel;/add(Ljava/awt/Component;Ljava/lang/Object;)V
	getstatic	ttt/j I
	iconst_1
	iadd
	putstatic	ttt/j I
	goto	L006
L005:
	getstatic	ttt/i I
	iconst_1
	iadd
	putstatic	ttt/i I
	goto	L002
L001:
;
; 022 for(i=0to3){upan[i].finish(pos[i]);}
;
	iconst_0
	putstatic	ttt/i I
L010:
	getstatic	ttt/i I
	iconst_3
	if_icmpgt	L011
	iconst_0
	goto	L012
L011:
	iconst_1
L012:
	ifne	L009
;
; 024 upan[i].finish(pos[i])
;

	getstatic	ttt/upan [Ljavax/swing/JPanel;
	getstatic	ttt/i I
	aaload
	getstatic	ttt/pos [Ljava/lang/String;
	getstatic	ttt/i I
	aaload
	invokevirtual	[Ljavax/swing/JPanel;/add(Ljava/awt/Component;Ljava/lang/Object;)V
	getstatic	ttt/i I
	iconst_1
	iadd
	putstatic	ttt/i I
	goto	L010
L009:

	invokestatic	java/time/Instant/now()Ljava/time/Instant;
	astore_2
	aload_1
	aload_2
	invokestatic	java/time/Duration/between(Ljava/time/temporal/Temporal;Ljava/time/temporal/Temporal;)Ljava/time/Duration;
	invokevirtual	java/time/Duration/toMillis()J
	lstore_3
	getstatic	java/lang/System/out Ljava/io/PrintStream;
	ldc	"\n[%,d milliseconds execution time.]\n"
	iconst_1
	anewarray	java/lang/Object
	dup
	iconst_0
	lload_3
	invokestatic	java/lang/Long/valueOf(J)Ljava/lang/Long;
	aastore
	invokevirtual	java/io/PrintStream/printf(Ljava/lang/String;[Ljava/lang/Object;)Ljava/io/PrintStream;
	pop

	getstatic	ttt/_mainframe Ljavax/swing/JFrame;
	dup
	invokevirtual	javax/swing/JFrame/pack()V
	ldc	1
	invokevirtual	javax/swing/JFrame/setVisible(Z)V

	return

.limit locals 6
.limit stack 29
.end method
