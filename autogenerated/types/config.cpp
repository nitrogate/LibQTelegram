// Generated by APIGenerator 1.0
// DO NOT EDIT!!!

#include "config.h"


Config::Config(QObject* parent) : TelegramObject(parent)
{
	this->_flags = 0;
	this->_date = 0;
	this->_expires = 0;
	this->_is_test_mode = false;
	this->_this_dc = 0;
	this->_chat_size_max = 0;
	this->_megagroup_size_max = 0;
	this->_forwarded_count_max = 0;
	this->_online_update_period_ms = 0;
	this->_offline_blur_timeout_ms = 0;
	this->_offline_idle_timeout_ms = 0;
	this->_online_cloud_timeout_ms = 0;
	this->_notify_cloud_delay_ms = 0;
	this->_notify_default_delay_ms = 0;
	this->_chat_big_size = 0;
	this->_push_chat_period_ms = 0;
	this->_push_chat_limit = 0;
	this->_saved_gifs_limit = 0;
	this->_edit_time_limit = 0;
	this->_rating_e_decay = 0;
	this->_stickers_recent_limit = 0;
	this->_tmp_sessions = 0;
	this->_constructorid = Config::CtorConfig;
}

void Config::read(MTProtoStream* mtstream) 
{
	this->_constructorid = mtstream->readTLConstructor();
	
	Q_ASSERT((this->_constructorid == Config::CtorConfig));
	
	if(this->_constructorid == Config::CtorConfig)
	{
		this->_flags = mtstream->readTLInt();
		this->_date = mtstream->readTLInt();
		this->_expires = mtstream->readTLInt();
		this->_is_test_mode = mtstream->readTLBool();
		this->_this_dc = mtstream->readTLInt();
		mtstream->readTLVector<DcOption>(this->_dc_options, false, this);
		this->_chat_size_max = mtstream->readTLInt();
		this->_megagroup_size_max = mtstream->readTLInt();
		this->_forwarded_count_max = mtstream->readTLInt();
		this->_online_update_period_ms = mtstream->readTLInt();
		this->_offline_blur_timeout_ms = mtstream->readTLInt();
		this->_offline_idle_timeout_ms = mtstream->readTLInt();
		this->_online_cloud_timeout_ms = mtstream->readTLInt();
		this->_notify_cloud_delay_ms = mtstream->readTLInt();
		this->_notify_default_delay_ms = mtstream->readTLInt();
		this->_chat_big_size = mtstream->readTLInt();
		this->_push_chat_period_ms = mtstream->readTLInt();
		this->_push_chat_limit = mtstream->readTLInt();
		this->_saved_gifs_limit = mtstream->readTLInt();
		this->_edit_time_limit = mtstream->readTLInt();
		this->_rating_e_decay = mtstream->readTLInt();
		this->_stickers_recent_limit = mtstream->readTLInt();
		if(IS_FLAG_SET(this->_flags, 0))
			this->_tmp_sessions = mtstream->readTLInt();
		
		mtstream->readTLVector<DisabledFeature>(this->_disabled_features, false, this);
	}
}

void Config::write(MTProtoStream* mtstream) 
{
	Q_ASSERT((this->_constructorid == Config::CtorConfig));
	
	this->compileFlags();
	mtstream->writeTLConstructor(this->_constructorid);
	
	if(this->_constructorid == Config::CtorConfig)
	{
		mtstream->writeTLInt(this->_flags);
		mtstream->writeTLInt(this->_date);
		mtstream->writeTLInt(this->_expires);
		mtstream->writeTLBool(this->_is_test_mode);
		mtstream->writeTLInt(this->_this_dc);
		mtstream->writeTLVector(this->_dc_options, false);
		mtstream->writeTLInt(this->_chat_size_max);
		mtstream->writeTLInt(this->_megagroup_size_max);
		mtstream->writeTLInt(this->_forwarded_count_max);
		mtstream->writeTLInt(this->_online_update_period_ms);
		mtstream->writeTLInt(this->_offline_blur_timeout_ms);
		mtstream->writeTLInt(this->_offline_idle_timeout_ms);
		mtstream->writeTLInt(this->_online_cloud_timeout_ms);
		mtstream->writeTLInt(this->_notify_cloud_delay_ms);
		mtstream->writeTLInt(this->_notify_default_delay_ms);
		mtstream->writeTLInt(this->_chat_big_size);
		mtstream->writeTLInt(this->_push_chat_period_ms);
		mtstream->writeTLInt(this->_push_chat_limit);
		mtstream->writeTLInt(this->_saved_gifs_limit);
		mtstream->writeTLInt(this->_edit_time_limit);
		mtstream->writeTLInt(this->_rating_e_decay);
		mtstream->writeTLInt(this->_stickers_recent_limit);
		if(IS_FLAG_SET(this->_flags, 0))
			mtstream->writeTLInt(this->_tmp_sessions);
		
		mtstream->writeTLVector(this->_disabled_features, false);
	}
}

void Config::compileFlags() 
{
	this->_flags = 0;
	
	if(this->_constructorid == Config::CtorConfig)
	{
		if(this->_tmp_sessions)
			SET_FLAG_BIT(this->_flags, 0);
	}
}

TLInt Config::flags() const
{
	return this->_flags;
}

void Config::setFlags(TLInt flags) 
{
	if(this->_flags == flags)
		return;

	this->_flags = flags;
	emit flagsChanged();
}

TLInt Config::date() const
{
	return this->_date;
}

void Config::setDate(TLInt date) 
{
	if(this->_date == date)
		return;

	this->_date = date;
	emit dateChanged();
}

TLInt Config::expires() const
{
	return this->_expires;
}

void Config::setExpires(TLInt expires) 
{
	if(this->_expires == expires)
		return;

	this->_expires = expires;
	emit expiresChanged();
}

TLBool Config::isTestMode() const
{
	return this->_is_test_mode;
}

void Config::setIsTestMode(TLBool is_test_mode) 
{
	if(this->_is_test_mode == is_test_mode)
		return;

	this->_is_test_mode = is_test_mode;
	emit isTestModeChanged();
}

TLInt Config::thisDc() const
{
	return this->_this_dc;
}

void Config::setThisDc(TLInt this_dc) 
{
	if(this->_this_dc == this_dc)
		return;

	this->_this_dc = this_dc;
	emit thisDcChanged();
}

const TLVector<DcOption*>& Config::dcOptions() const
{
	return this->_dc_options;
}

void Config::setDcOptions(const TLVector<DcOption*>& dc_options) 
{
	if(this->_dc_options == dc_options)
		return;

	this->_dc_options = dc_options;
	emit dcOptionsChanged();
}

TLInt Config::chatSizeMax() const
{
	return this->_chat_size_max;
}

void Config::setChatSizeMax(TLInt chat_size_max) 
{
	if(this->_chat_size_max == chat_size_max)
		return;

	this->_chat_size_max = chat_size_max;
	emit chatSizeMaxChanged();
}

TLInt Config::megagroupSizeMax() const
{
	return this->_megagroup_size_max;
}

void Config::setMegagroupSizeMax(TLInt megagroup_size_max) 
{
	if(this->_megagroup_size_max == megagroup_size_max)
		return;

	this->_megagroup_size_max = megagroup_size_max;
	emit megagroupSizeMaxChanged();
}

TLInt Config::forwardedCountMax() const
{
	return this->_forwarded_count_max;
}

void Config::setForwardedCountMax(TLInt forwarded_count_max) 
{
	if(this->_forwarded_count_max == forwarded_count_max)
		return;

	this->_forwarded_count_max = forwarded_count_max;
	emit forwardedCountMaxChanged();
}

TLInt Config::onlineUpdatePeriodMs() const
{
	return this->_online_update_period_ms;
}

void Config::setOnlineUpdatePeriodMs(TLInt online_update_period_ms) 
{
	if(this->_online_update_period_ms == online_update_period_ms)
		return;

	this->_online_update_period_ms = online_update_period_ms;
	emit onlineUpdatePeriodMsChanged();
}

TLInt Config::offlineBlurTimeoutMs() const
{
	return this->_offline_blur_timeout_ms;
}

void Config::setOfflineBlurTimeoutMs(TLInt offline_blur_timeout_ms) 
{
	if(this->_offline_blur_timeout_ms == offline_blur_timeout_ms)
		return;

	this->_offline_blur_timeout_ms = offline_blur_timeout_ms;
	emit offlineBlurTimeoutMsChanged();
}

TLInt Config::offlineIdleTimeoutMs() const
{
	return this->_offline_idle_timeout_ms;
}

void Config::setOfflineIdleTimeoutMs(TLInt offline_idle_timeout_ms) 
{
	if(this->_offline_idle_timeout_ms == offline_idle_timeout_ms)
		return;

	this->_offline_idle_timeout_ms = offline_idle_timeout_ms;
	emit offlineIdleTimeoutMsChanged();
}

TLInt Config::onlineCloudTimeoutMs() const
{
	return this->_online_cloud_timeout_ms;
}

void Config::setOnlineCloudTimeoutMs(TLInt online_cloud_timeout_ms) 
{
	if(this->_online_cloud_timeout_ms == online_cloud_timeout_ms)
		return;

	this->_online_cloud_timeout_ms = online_cloud_timeout_ms;
	emit onlineCloudTimeoutMsChanged();
}

TLInt Config::notifyCloudDelayMs() const
{
	return this->_notify_cloud_delay_ms;
}

void Config::setNotifyCloudDelayMs(TLInt notify_cloud_delay_ms) 
{
	if(this->_notify_cloud_delay_ms == notify_cloud_delay_ms)
		return;

	this->_notify_cloud_delay_ms = notify_cloud_delay_ms;
	emit notifyCloudDelayMsChanged();
}

TLInt Config::notifyDefaultDelayMs() const
{
	return this->_notify_default_delay_ms;
}

void Config::setNotifyDefaultDelayMs(TLInt notify_default_delay_ms) 
{
	if(this->_notify_default_delay_ms == notify_default_delay_ms)
		return;

	this->_notify_default_delay_ms = notify_default_delay_ms;
	emit notifyDefaultDelayMsChanged();
}

TLInt Config::chatBigSize() const
{
	return this->_chat_big_size;
}

void Config::setChatBigSize(TLInt chat_big_size) 
{
	if(this->_chat_big_size == chat_big_size)
		return;

	this->_chat_big_size = chat_big_size;
	emit chatBigSizeChanged();
}

TLInt Config::pushChatPeriodMs() const
{
	return this->_push_chat_period_ms;
}

void Config::setPushChatPeriodMs(TLInt push_chat_period_ms) 
{
	if(this->_push_chat_period_ms == push_chat_period_ms)
		return;

	this->_push_chat_period_ms = push_chat_period_ms;
	emit pushChatPeriodMsChanged();
}

TLInt Config::pushChatLimit() const
{
	return this->_push_chat_limit;
}

void Config::setPushChatLimit(TLInt push_chat_limit) 
{
	if(this->_push_chat_limit == push_chat_limit)
		return;

	this->_push_chat_limit = push_chat_limit;
	emit pushChatLimitChanged();
}

TLInt Config::savedGifsLimit() const
{
	return this->_saved_gifs_limit;
}

void Config::setSavedGifsLimit(TLInt saved_gifs_limit) 
{
	if(this->_saved_gifs_limit == saved_gifs_limit)
		return;

	this->_saved_gifs_limit = saved_gifs_limit;
	emit savedGifsLimitChanged();
}

TLInt Config::editTimeLimit() const
{
	return this->_edit_time_limit;
}

void Config::setEditTimeLimit(TLInt edit_time_limit) 
{
	if(this->_edit_time_limit == edit_time_limit)
		return;

	this->_edit_time_limit = edit_time_limit;
	emit editTimeLimitChanged();
}

TLInt Config::ratingEDecay() const
{
	return this->_rating_e_decay;
}

void Config::setRatingEDecay(TLInt rating_e_decay) 
{
	if(this->_rating_e_decay == rating_e_decay)
		return;

	this->_rating_e_decay = rating_e_decay;
	emit ratingEDecayChanged();
}

TLInt Config::stickersRecentLimit() const
{
	return this->_stickers_recent_limit;
}

void Config::setStickersRecentLimit(TLInt stickers_recent_limit) 
{
	if(this->_stickers_recent_limit == stickers_recent_limit)
		return;

	this->_stickers_recent_limit = stickers_recent_limit;
	emit stickersRecentLimitChanged();
}

TLInt Config::tmpSessions() const
{
	return this->_tmp_sessions;
}

void Config::setTmpSessions(TLInt tmp_sessions) 
{
	if(this->_tmp_sessions == tmp_sessions)
		return;

	this->_tmp_sessions = tmp_sessions;
	emit tmpSessionsChanged();
}

const TLVector<DisabledFeature*>& Config::disabledFeatures() const
{
	return this->_disabled_features;
}

void Config::setDisabledFeatures(const TLVector<DisabledFeature*>& disabled_features) 
{
	if(this->_disabled_features == disabled_features)
		return;

	this->_disabled_features = disabled_features;
	emit disabledFeaturesChanged();
}

