/*
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 */
#if !defined(DMRAccessControl_H)
#define	DMRAccessControl_H

#include <vector>
#include <ctime>
#include "DMRLC.h"

class CDMRAccessControl {
public:
	static bool validateAccess(unsigned int srcId, unsigned int dstId, unsigned int slot, bool network);

<<<<<<< HEAD
	static void init(const std::vector<unsigned int>& DstIdBlacklistSlot1RF, const std::vector<unsigned int>& DstIdWhitelistSlot1RF, const std::vector<unsigned int>& DstIdBlacklistSlot2RF, const std::vector<unsigned int>& DstIdWhitelistSlot2RF, const std::vector<unsigned int>& DstIdBlacklistSlot1NET, const std::vector<unsigned int>& DstIdWhitelistSlot1NET, const std::vector<unsigned int>& DstIdBlacklistSlot2NET, const std::vector<unsigned int>& DstIdWhitelistSlot2NET, const std::vector<unsigned int>& SrcIdBlacklist, bool selfOnly, const std::vector<unsigned int>& prefixes,unsigned int id,unsigned int callHang, bool TGRewrteSlot1, bool TGRewrteSlot2, bool m_BMAutoRewrite, bool m_BMRewriteReflectorVoicePrompts);
	
	static unsigned int DstIdRewrite(unsigned int id, unsigned int sid,unsigned int slot, bool network, CDMRLC* dmrLC);
=======
	static void init(const std::vector<unsigned int>& dstIdBlacklistSlot1RF, const std::vector<unsigned int>& dstIdWhitelistSlot1RF, const std::vector<unsigned int>& dstIdBlacklistSlot2RF, const std::vector<unsigned int>& dstIdWhitelistSlot2RF, const std::vector<unsigned int>& dstIdBlacklistSlot1NET, const std::vector<unsigned int>& dstIdWhitelistSlot1NET, const std::vector<unsigned int>& dstIdBlacklistSlot2NET, const std::vector<unsigned int>& dstIdWhitelistSlot2NET, const std::vector<unsigned int>& srcIdBlacklist, bool selfOnly, const std::vector<unsigned int>& prefixes, unsigned int id, unsigned int callHang, bool tgRewrteSlot1, bool tgRewrteSlot2);
	
	static unsigned int dstIdRewrite(unsigned int id, unsigned int sid,unsigned int slot, bool network);

>>>>>>> upstream/master
	static void setOverEndTime();

private:
	static std::vector<unsigned int> m_dstBlackListSlot1RF;
	static std::vector<unsigned int> m_dstBlackListSlot2RF;
	static std::vector<unsigned int> m_dstWhiteListSlot1RF;
	static std::vector<unsigned int> m_dstWhiteListSlot2RF;

	static std::vector<unsigned int> m_dstBlackListSlot1NET;
	static std::vector<unsigned int> m_dstBlackListSlot2NET;
	static std::vector<unsigned int> m_dstWhiteListSlot1NET;
	static std::vector<unsigned int> m_dstWhiteListSlot2NET;

	static std::vector<unsigned int> m_srcIdBlacklist;

	static std::vector<unsigned int> m_prefixes;
	
	static unsigned int m_callHang;

	static bool m_selfOnly;
	static unsigned int m_id;

	static bool dstIdBlacklist(unsigned int did,unsigned int slot, bool network);
	static bool dstIdWhitelist(unsigned int did,unsigned int slot,bool gt4k, bool network);

	static bool validateSrcId(unsigned int id);
	
	static std::time_t m_time;
	
	static unsigned int m_dstRewriteID;
<<<<<<< HEAD
	static unsigned int m_SrcID;
	
	static bool m_TGRewriteSlot1;
	static bool m_TGRewriteSlot2;
	static bool m_BMAutoRewrite;
	static bool m_BMRewriteReflectorVoicePrompts;
	
	static CDMRLC* m_lastdmrLC;

=======
	static unsigned int m_srcID;
>>>>>>> upstream/master
	
	static bool m_tgRewriteSlot1;
	static bool m_tgRewriteSlot2;
};

#endif
