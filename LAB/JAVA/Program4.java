// Program 4 Add Two Distances Using Object Parameters

import java.util.Scanner;

class Distance {
    int feet, inches;

    public void getDistance() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter feet: ");
        feet = sc.nextInt();
        System.out.print("Enter inches: ");
        inches = sc.nextInt();
    }

    public void showDistance() {
        System.out.println(feet + " feet " + inches + " inches");
    }

    public void addDistance(Distance d1, Distance d2) {
        this.feet = d1.feet + d2.feet;
        this.inches = d1.inches + d2.inches;

        if (this.inches >= 12) {
            this.feet += this.inches / 12;
            this.inches = this.inches % 12;
        }
    }
}

public class Program4 {
    public static void main(String[] args) {
        Distance d1 = new Distance();
        Distance d2 = new Distance();
        Distance d3 = new Distance();

        System.out.println("Enter 1st distance:");
        d1.getDistance();
        System.out.println("Enter 2nd distance:");
        d2.getDistance();

        d3.addDistance(d1, d2);

        System.out.println("1st Distance:");
        d1.showDistance();
        System.out.println("2nd Distance:");
        d2.showDistance();
        System.out.println("Total Distance:");
        d3.showDistance();
    }
}