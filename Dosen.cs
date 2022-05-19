using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace UTS_BAGUS
{
    internal class Dosen
    {
        private int id { get; set; }
        private string name { get; set; }
        private int nik { get; set; }
        private string gender { get; set; }
        private string course { get; set; }

        public Dosen(int id, string name, int nik, string gander, string course)
        {
            this.id = id;
            this.name = name;
            this.nik = nik;
            this.gender = gander;
            this.course = course;
        }
        public void cetakHasil()
        {
            Console.WriteLine("Data Default Dosen");
            Console.WriteLine();
            Console.WriteLine($"ID : {this.id}");
            Console.WriteLine($"Name : {this.name}");
            Console.WriteLine($"NIK : {this.nik}");
            Console.WriteLine($"Gender : {this.gender}");
            Console.WriteLine($"Course : {this.course}");
        }

        public void addDosen()
        {
            Console.Write("Inputkan Nama Dosen Terbaru : ");
            this.name = Console.ReadLine();
            Console.Write("Inputkan NIK Dosen Terbaru : ");
            this.nik = Convert.ToInt32(Console.ReadLine());
        }

        public string addCourse()
        {
            Console.Write($"Inputkan Course {this.name} : ");
            this.course = Console.ReadLine();

            return this.name;
        }

        public void cetakAkhir()
        {
            Console.WriteLine("Data Dosen Terbaru");
            Console.WriteLine();
            Console.WriteLine($"Name : {this.name}");
            Console.WriteLine($"NIK : {this.nik}");
            Console.WriteLine($"Course : {this.course}");
        }
    }
}
