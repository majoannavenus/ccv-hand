//
// FormattingChannel.h
//
// $Id: //poco/1.3/Foundation/include/Poco/FormattingChannel.h#1 $
//
// Library: Foundation
// Package: Logging
// Module:  Formatter
//
// Definition of the FormattingChannel class.
//
// Copyright (c) 2004-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Foundation_FormattingChannel_INCLUDED
#define Foundation_FormattingChannel_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/Channel.h"


namespace Poco {


class Formatter;


class Foundation_API FormattingChannel: public Channel
	/// The FormattingChannel is a filter channel that routes
	/// a Message through a Formatter before passing it on
	/// to the destination channel.
{
public:
	FormattingChannel();
		/// Creates a FormattingChannel.
		
	FormattingChannel(Formatter* pFormatter);
		/// Creates a FormattingChannel and attaches a Formatter.
		
	FormattingChannel(Formatter* pFormatter, Channel* pChannel);
		/// Creates a FormattingChannel and attaches a Formatter
		/// and a Channel.
		
	void setFormatter(Formatter* pFormatter);
		/// Sets the Formatter used to format the messages
		/// before they are passed on. If null, the message
		/// is passed on unmodified.
		
	Formatter* getFormatter() const;
		/// Returns the Formatter used to format messages,
		/// which may be null.

	void setChannel(Channel* pChannel);
		/// Sets the destination channel to which the formatted 
		/// messages are passed on.
		
	Channel* getChannel() const;
		/// Returns the channel to which the formatted
		/// messages are passed on.
		
	void log(const Message& msg);
		/// Formats the given Message using the Formatter and
		/// passes the formatted message on to the destination
		/// Channel.

	void setProperty(const std::string& name, const std::string& value);
		/// Sets or changes a configuration property.
		///
		/// Only the "channel" and "formatter" properties are supported, which allow
		/// setting the target channel and formatter, respectively, via the LoggingRegistry.
		/// The "channel" and "formatter" properties are set-only.
		///
		/// Unsupported properties are passed to the attached Channel.

	void open();
		/// Opens the attached channel.
		
	void close();
		/// Closes the attached channel.

protected:
	~FormattingChannel();

private:
	Formatter* _pFormatter;
	Channel* _pChannel;
};


} // namespace Poco


#endif // Foundation_FormattingChannel_INCLUDED
