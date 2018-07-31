// Copyright (c) 2017-2018 The Popchain Core Developers

#include "primitives/block.h"

#include "hash.h"
#include "tinyformat.h"
#include "utilstrencodings.h"
//#include "crypto/common.h"

uint256 CBlockHeader::GetHash() const
{
//	return SerializeHash(*this);
	uint256 hash;
/*popchain ghost*/
	CryptoPop(this, (unsigned char *)&hash);
/*popchain ghost*/

//	view_data_u8("PoW 3", (unsigned char *)&hash, OUTPUT_LEN); 
//	std::cout<<"gethex() ="<<hash.GetHex()<<std::endl;
//	std::cout<<"tostring ="<<hash.ToString()<<std::endl; 
	return hash;	
}

std::string CBlockHeader::ToString() const                                                                                                                                                                                                                                   
{
/*popchain ghost*/
    std::stringstream s;
    s << strprintf("CBlock(hash=%s, ver=%d, hashUncles=%s, nCoinbase=%s, nDifficulty=%s, nNumber=%u, hashPrevBlock=%s, hashMerkleRoot=%s, hashClaimTrie=%s, nTime=%u, nBits=%08x, nNonce=%s)\n",
		GetHash().ToString(),
        nVersion,
        hashPrevBlock.ToString(),
        hashUncles.ToString(),
        nCoinbase.ToString(),/*change by base58 ?*/
        nDifficulty.ToString(),
        nNumber,
        hashMerkleRoot.ToString(),
        hashClaimTrie.ToString(),
        nTime, nBits, nNonce.ToString());
/*popchain ghost*/
    return s.str();
}

std::string CBlock::ToString() const
{
    std::stringstream s;
    s << strprintf("CBlock(hash=%s, ver=%d, hashUncles=%s, nCoinbaseAddress=%s, nDifficulty=%s, nNumber=%u, hashPrevBlock=%s, hashMerkleRoot=%s, hashClaimTrie=%s, nTime=%u, nBits=%08x, nNonce=%s, vtx=%u)\n",
        GetHash().ToString(),
        nVersion,
        hashPrevBlock.ToString(),
        hashUncles.ToString(),/*popchain ghost*/
        nCoinbase.ToString(),/*popchain ghost*/
        nDifficulty.ToString(),/*popchain ghost*/
        nNumber,/*popchain ghost*/
        hashMerkleRoot.ToString(),
        hashClaimTrie.ToString(),
        nTime, nBits, nNonce.ToString(),
        vtx.size(),
        vuh.size()/*popchain ghost*/);
    for (unsigned int i = 0; i < vtx.size(); i++)
    {
        s << "  " << vtx[i].ToString() << "\n";
    }
    return s.str();
}
