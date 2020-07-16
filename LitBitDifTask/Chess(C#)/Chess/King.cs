using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Chess
{
    class King : Piece
    {
        MyColor KingColor;
        public King(MyColor C, string n) : base(C, n)
        {
            col = C;
            KingColor = C;
            PictureName = n;
            IsKing = true;
        }

        
        public override bool IsLegal(int sr, int sc, int er, int ec, Piece[,] Ps)
        {
            if (((Math.Abs(sr - er) == 1 && sc == ec) || (Math.Abs(sc - ec) == 1 && sr == er)
                 || (Math.Abs(sc - ec) == 1 && Math.Abs(sr - er) == 1)) && (Ps[er, ec] == null || Ps[er, ec].col != KingColor))
                return true;
            else
                return false;
        }
    }
}
