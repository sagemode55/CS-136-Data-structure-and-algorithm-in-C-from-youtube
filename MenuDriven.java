package menudriven;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Scanner;

public class MenuDriven {

    List<Inventory> result = new ArrayList<Inventory>();
    List<Inventory> errorResult = new ArrayList<Inventory>();
    BufferedReader br = null;
    Inventory invent;

    public static boolean validateItemId(String itemId) {

        if (itemId.length() == 5) {
            return true;
        }

        return false;
    }

    public static boolean validateItemName(String itemName) {

        if (itemName.matches("[a-zA-Z]*")) {
            return true;
        }

        return false;
    }

    public void getData() {

        try {

            br = new BufferedReader(new FileReader("data.txt"));

            String line;
            while ((line = br.readLine()) != null) {
                String lines[] = line.split(" ");
                if (validateItemId(lines[0]) == false && validateItemName(lines[1]) == false) {

                    try (FileWriter writer = new FileWriter("error.txt", true);
                            BufferedWriter bw = new BufferedWriter(writer)) {

                        bw.write(lines[0] + " " + lines[1] + " " + Integer.parseInt(lines[2]) + " " + Double.parseDouble(lines[3]) + " error Message : Item Id must be five charactar and name should be alphabetic " + "\n");
                        invent = new Inventory(lines[0], lines[1], Integer.parseInt(lines[2]), Double.parseDouble(lines[3]));
                        invent.setStatus(" error Message : Item Id must be five charactar and name should be alphabetic ");
                        errorResult.add(invent);
                    } catch (IOException e) {
                        System.err.format("IOException: %s%n", e);
                    }
                    continue;

                } else if (validateItemId(lines[0]) == false) {

                    try (FileWriter writer = new FileWriter("error.txt", true);
                            BufferedWriter bw = new BufferedWriter(writer)) {

                        bw.write(lines[0] + " " + lines[1] + " " + Integer.parseInt(lines[2]) + " " + Double.parseDouble(lines[3]) + " error Message : Item Id must be five charactar" + "\n");
                        invent = new Inventory(lines[0], lines[1], Integer.parseInt(lines[2]), Double.parseDouble(lines[3]));
                        invent.setStatus(" error Message : Item Id must be five charactar");
                        errorResult.add(invent);
                    } catch (IOException e) {
                        System.err.format("IOException: %s%n", e);
                    }
                    continue;

                } else if (validateItemName(lines[1]) == false) {

                    try (FileWriter writer = new FileWriter("error.txt", true);
                            BufferedWriter bw = new BufferedWriter(writer)) {

                        bw.write(lines[0] + " " + lines[1] + " " + Integer.parseInt(lines[2]) + " " + Double.parseDouble(lines[3]) + " error Message : name should be alphabetic" + "\n");
                        invent = new Inventory(lines[0], lines[1], Integer.parseInt(lines[2]), Double.parseDouble(lines[3]));
                        invent.setStatus(" error Message : name should be alphabetic");
                        errorResult.add(invent);
                    } catch (IOException e) {
                        System.err.format("IOException: %s%n", e);
                    }
                    continue;

                }
                invent = new Inventory(lines[0], lines[1], Integer.parseInt(lines[2]), Double.parseDouble(lines[3]));
                Random rand = new Random();
                int data = rand.nextInt(3);
                String array[] = {"Active", "Discontinued", "Recalled"};

                invent.setStatus("" + Status.valueOf(array[data]));

                result.add(invent);
            }

            br.close();

        } catch (IOException e) {
            System.out.println(e + "Error");
        }

    }

    public static void print(List<Inventory> result) {

        for (Inventory ob : result) {
            System.out.format("%1s%14s%14d%14s%16s", ob.getItemId(), ob.getItemName(), ob.getQuantity(), "" + ob.getPrice(), ob.getStatus());
            System.out.println("");
        }
    }

    public boolean isValidRec(String str1, String str2) {

        if (validateItemId(str1) && validateItemName(str2)) {
            return true;
        }

        return false;
    }

    public static void main(String[] args) {

        MenuDriven object = new MenuDriven();
        object.getData();

        boolean checker = true;
        while (checker) {

            try {
                System.out.println("\n_________________Welcome to our page________________\n");
                System.out.println("1. print all items in the inventory unsorted\n"
                        + "2. print invalid records from an error file\n"
                        + "3. search for an item by ID or name\n4. Print a report\n5. print all items regardless of their status\n6. sort inventory list by itemname\n7. quit the game");
                System.out.print("Please enter option: ");
                int option = new Scanner(System.in).nextInt();
                switch (option) {

                    case 1:
                        System.out.println("\n");

                        print(object.result);
                        break;
                    case 2:
                        System.out.println("\n");
                        for (Inventory ob : object.errorResult) {
                            System.out.format("%-14s%-14s%-14d%-14s%-20s", ob.getItemId(), ob.getItemName(), ob.getQuantity(), "" + ob.getPrice(), ob.getStatus());
                            System.out.println("");
                        }
                        System.out.println("");
                        break;
                    case 3:

                        System.out.print("\n1. Search by Item ID\n2. Search by Item Name \nPlease choose : - ");
                        int choose = new Scanner(System.in).nextInt();

                        if (choose == 1) {

                            System.out.print("\nPlease enter Item ID: ");
                            String itemID = new Scanner(System.in).nextLine();
                            boolean found = false;
                            for (Inventory ob : object.result) {
                                if (itemID.equals(ob.getItemId())) {
                                    System.out.println("\n\n!!!! -   Item Found   - !!!!");
                                    System.out.println("Item description: ");
                                    System.out.format("%1s%14s%14d%14s%16s", ob.getItemId(), ob.getItemName(), ob.getQuantity(), "" + ob.getPrice(), ob.getStatus());
                                    System.out.println("");
                                    found = true;
                                    break;
                                }
                            }
                            if (found == false) {
                                System.out.println("\n!!!! -   Item Not Found- please try again  - !!!!\n");
                            }

                        } else if (choose == 2) {

                            System.out.println("\nPlease enter Item Name: ");
                            String itemName = new Scanner(System.in).nextLine();
                            boolean found = false;
                            for (Inventory ob : object.result) {
                                if (itemName.toLowerCase().equals(ob.getItemName().toLowerCase())) {
                                    System.out.println("\nItem description: ");
                                    System.out.format("%1s%14s%14d%14s%16s", ob.getItemId(), ob.getItemName(), ob.getQuantity(), ""+ob.getPrice(),ob.getStatus());
                                    System.out.println("");

                                    found = true;
                                    break;
                                }
                            }
                            if (found == false) {
                                System.out.println("!!!! -   Item Not Found- please try again  - !!!!\n");
                            }
                        } else {
                            System.out.println("Please choose only two option [1,2] : see you again !!\n");
                        }

                        break;

                    case 4:
                        Map<String, Integer> mapObject = new HashMap<String, Integer>();

                        for (Inventory in : object.result) {

                            if (mapObject.containsKey(in.getItemName())) {
                                mapObject.put(in.getItemName(), mapObject.get(in.getItemName()) + 1);
                            } else {
                                mapObject.put(in.getItemName(), 1);
                            }

                        }
                        System.out.println("\n\nTotal Number of Unique Items : " + mapObject.size());

                        double totalWorth = 0;
                        for (Inventory ob : object.result) {
                            totalWorth += ob.getQuantity() * ob.getPrice();
                        }
                        System.out.println("The Total worth of the inventory : " + totalWorth);
                        System.out.println("The Total Count of all items in the inventory : " + object.result.size() + "\n\n");

                        break;
                    case 5:

                        System.out.print("1. Print all Active items\n2. Print all Discontinued items\n3. Print all Recall items\nPlease choose: ");
                        int choice = new Scanner(System.in).nextInt();

                        if (choice == 1) {
                            int count = 0;
                            for (Inventory ob : object.result) {
                                if (ob.getStatus().equals("Active")) {
                                    count++;
                                    System.out.format("%1s%14s%14d%14s%16s", ob.getItemId(), ob.getItemName(), ob.getQuantity(), "" + ob.getPrice(), ob.getStatus());
                                    System.out.println("");
                                }
                            }
                            if (count == 0) {
                                System.out.println("No Item Found with Active status");
                            }

                        } else if (choice == 2) {

                            int count = 0;
                            for (Inventory ob : object.result) {
                                if (ob.getStatus().equals("Discontinued")) {
                                    count++;
                                    System.out.format("%1s%14s%14d%14s%16s", ob.getItemId(), ob.getItemName(), ob.getQuantity(), "" + ob.getPrice(), ob.getStatus());
                                    System.out.println("");
                                }
                            }
                            if (count == 0) {
                                System.out.println("No Item Found with Discontinued status");
                            }

                        } else if (choice == 3) {
                            int count = 0;
                            for (Inventory ob : object.result) {
                                if (ob.getStatus().equals("Recall")) {
                                    count++;
                                    System.out.format("%1s%14s%14d%14s%16s", ob.getItemId(), ob.getItemName(), ob.getQuantity(), "" + ob.getPrice(), ob.getStatus());
                                    System.out.println("");
                                }
                            }
                            if (count == 0) {
                                System.out.println("No Item Found with Recall status");
                            }
                        }

                        break;
                    case 6:
                        List<String> stringList = new ArrayList<String>();

                        for (Inventory ob : object.result) {

                            stringList.add(ob.getItemName());

                        }

                        Collections.sort(stringList);
                        System.out.println();
                        for (String ob1 : stringList) {
                            for (Inventory ob : object.result) {
                                if (ob1.equals(ob.getItemName())) {
//                                    System.out.println(ob.getItemId() + "   " + ob.getItemName() + "     " + ob.getQuantity() + "    " + ob.getPrice() + "        " + ob.getStatus());
                                    System.out.format("%1s%14s%14d%14s%16s", ob.getItemId(), ob.getItemName(), ob.getQuantity(), "" + ob.getPrice(), ob.getStatus());
                                    System.out.println("");
                                    break;
                                }
                            }
                        }

                        break;
                    case 7:

                        checker = false;

                        System.out.println("Thanks for using ByBye!!");
                        break;

                }

            } catch (Exception e) {
                System.out.println(e + "Something went wrong");
            }

        }

    }

}
