# Secure Communication Between Two EC2 Instances in AWS

## Aim
To create a cloud-based environment where two virtual machines communicate securely within a virtual network and transfer files securely using SSH and SCP.

---

## Architecture

- One Public EC2 Instance (Bastion Host)
- One Private EC2 Instance
- Both instances inside the same VPC
- Secure communication using SSH
- File transfer using SCP

---

## Step 1: Create a VPC

1. Open AWS Console
2. Go to **VPC Dashboard**
3. Click **Create VPC**
4. Select:
   - VPC only
5. Enter:
   - **Name:** `project-vpc`
   - **IPv4 CIDR:** `10.0.0.0/16`
6. Create the VPC

---

## Step 2: Create Public EC2 Instance (Instance-1)

1. Go to **EC2 Dashboard**
2. Click **Launch Instance**
3. Configure:
   - **Name:** `instance-1`
   - **AMI:** Ubuntu
   - **Instance Type:** t2.micro
4. Select:
   - **VPC:** `project-vpc`
   - **Public Subnet**
5. Enable:
   - Auto Assign Public IP
6. Create/Select key pair:
   - `tingu.pem`
7. Create Security Group:
   - Allow SSH
   - Source: `0.0.0.0/0`
8. Launch Instance

---

## Step 3: Create Private EC2 Instance (Instance-2)

1. Launch another EC2 instance
2. Configure:
   - **Name:** `instance-2`
   - **AMI:** Ubuntu
   - **Instance Type:** t2.micro
3. Select:
   - **Same VPC:** `project-vpc`
   - **Private Subnet**
4. Disable:
   - Auto Assign Public IP
5. Use same key pair:
   - `tingu.pem`
6. Create Security Group:
   - Allow SSH
   - Source: Security Group of Instance-1
7. Launch Instance

---

## Step 4: Connect to Public Instance

Open terminal and run:

```bash
ssh -i tingu.pem ubuntu@PUBLIC_IP_OF_INSTANCE1
```

---

## Step 5: Copy PEM Key to Instance-1

Open another terminal on local machine:

```bash
scp -i tingu.pem tingu.pem ubuntu@PUBLIC_IP_OF_INSTANCE1:/home/ubuntu/
```

---

## Step 6: Change Key Permissions

Inside instance-1:

```bash
chmod 400 tingu.pem
```

---

## Step 7: Connect to Private Instance

Inside instance-1:

```bash
ssh -i tingu.pem ubuntu@PRIVATE_IP_OF_INSTANCE2
```

Successful login confirms secure communication between instances.

---

## Step 8: Create File in Instance-1

```bash
echo "Hello from Instance 1" > test.txt
```

---

## Step 9: Transfer File to Instance-2

```bash
scp -i tingu.pem test.txt ubuntu@PRIVATE_IP_OF_INSTANCE2:/home/ubuntu/
```

---

## Step 10: Verify File Transfer

SSH into instance-2:

```bash
ssh -i tingu.pem ubuntu@PRIVATE_IP_OF_INSTANCE2
```

Check file:

```bash
cat test.txt
```

**Output:**

```
Hello from Instance 1
```

---

## Result

- Successfully created a secure cloud environment using AWS VPC
- Established secure communication between two EC2 instances
- Implemented secure file transfer using SCP
- Applied proper access control using Security Groups and PEM authentication

---

## Technologies Used

- AWS EC2
- AWS VPC
- SSH
- SCP
- Ubuntu Linux
