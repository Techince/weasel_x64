module;
#include "stdafx.h"
export module ContextUpdater;
import Deserializer;
import WeaselCommon;

export
{
	class ContextUpdater : public weasel::Deserializer
	{
	public:
		ContextUpdater(weasel::ResponseParser* pTarget);
		virtual ~ContextUpdater();
		virtual void Store(weasel::Deserializer::KeyType const& key, std::wstring const& value);

		void _StoreText(weasel::Text& target, Deserializer::KeyType k, std::wstring const& value);
		void _StoreCand(Deserializer::KeyType k, std::wstring const& value);

		static weasel::Deserializer::Ptr Create(weasel::ResponseParser* pTarget);
	};

	class StatusUpdater : public weasel::Deserializer
	{
	public:
		StatusUpdater(weasel::ResponseParser* pTarget);
		virtual ~StatusUpdater();
		virtual void Store(weasel::Deserializer::KeyType const& key, std::wstring const& value);

		static weasel::Deserializer::Ptr Create(weasel::ResponseParser* pTarget);
	};
}