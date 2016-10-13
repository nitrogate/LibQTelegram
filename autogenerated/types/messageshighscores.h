#ifndef MESSAGESHIGHSCORES_H
#define MESSAGESHIGHSCORES_H

// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "../../types/basic.h"
#include "../../types/telegramobject.h"
#include "highscore.h"
#include "user.h"

class MessagesHighScores: public TelegramObject
{
	Q_OBJECT

	Q_PROPERTY(TLVector<HighScore*> scores READ scores WRITE setScores NOTIFY scoresChanged)
	Q_PROPERTY(TLVector<User*> users READ users WRITE setUsers NOTIFY usersChanged)

	Q_ENUMS(Constructors)

	public:
		enum Constructors {
			CtorMessagesHighScores = 0x9a3bfd99,
		};

	public:
		explicit MessagesHighScores(QObject* parent = 0);
		virtual void read(MTProtoStream* mtstream);
		virtual void write(MTProtoStream* mtstream);
	protected:
		virtual void compileFlags();
	public:
		const TLVector<HighScore*>& scores() const;
		void setScores(const TLVector<HighScore*>& scores);
		const TLVector<User*>& users() const;
		void setUsers(const TLVector<User*>& users);

	signals:
		void scoresChanged();
		void usersChanged();

	private:
		TLVector<HighScore*> _scores;
		TLVector<User*> _users;

};

#endif // MESSAGESHIGHSCORES_H
