using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Chess
{
    class Pawn : Piece
    {
        MyColor PawnColor;

        public Pawn(MyColor C, string n) : base(C, n)
        {
            col = C;
            PawnColor = C;
            PictureName = n;
            IsKing = false;
        }

        public override bool IsLegal(int sr, int sc, int er, int ec, Piece[ , ] Ps)
        {
            if (PawnColor == MyColor.Black && sr == 1 && (er == 2 || er == 3) && ec == sc
                && (Ps[er, ec] == null) && VerticallyClear(sr, sc, er, ec, Ps) == true)
                return true;
            else if (PawnColor == MyColor.Black && sr - er == -1 && ec == sc && Ps[er, ec]==null)
                return true;
            else if (PawnColor == MyColor.Black && (Math.Abs(sc - ec) == 1 && sr - er == -1) 
                && (DiagonallyClearPawn(sr, sc, er, ec, Ps) == false) && ( Ps[er, ec].col != PawnColor))
                return true;
            else if (PawnColor == MyColor.White && sr == 6 && (er == 5 || er == 4) && ec == sc 
                && (Ps[er, ec] == null) && VerticallyClear(sr, sc, er, ec, Ps) == true)
                return true;
            else if (PawnColor == MyColor.White && sr-er==1 && ec == sc && Ps[er, ec] == null)
                return true;
            else if (PawnColor == MyColor.White && (Math.Abs(sc-ec)==1 && sr-er == 1) 
                && DiagonallyClearPawn(sr, sc, er, ec, Ps) == false && (Ps[er, ec] != null && Ps[er, ec].col != PawnColor))
                return true;
            return false;
        }
    }
}
